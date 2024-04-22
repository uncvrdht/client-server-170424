#include <windows.h>
#include <string>
#include <conio.h> 

#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string destFolder = "C:/Users/shago/1/";
    string srcURL = "https://source.unsplash.com/random/1280x720/?car";
    int count = 0;
    printf("Нажмите Enter для закачивания картинки\n");

    while (true)
    {
        if (_kbhit() && _getch() == '\r')
        {
            string destFile = destFolder + to_string(count++) + ".jpg";

            if (S_OK == URLDownloadToFileA(NULL, srcURL.c_str(), destFile.c_str(), 0, NULL))
            {
                printf("Сохранено в %s\n", destFile.c_str());
            }
            else
            {
                printf("Ошибка при загрузке изображения.\n");
                printf("Проверьте свое интернет соединение.\n");
                printf("Либо проверьте, существует ли путь: %s.\n", destFolder.c_str());
            }
        }
    }

    return 0;
}