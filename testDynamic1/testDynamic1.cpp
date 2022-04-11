// testDynamic1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include <Windows.h>

typedef int (group)(int);
typedef void(name)(char*);
typedef HINSTANCE HMODULE; 


int main()
{
    HINSTANCE hDll = LoadLibrary(L"C:\\Users\\wylia\\OneDrive\\Documentos\\РИ-571227\\РИ-571227-2\\Информационная безопасность телекоммуникационных систем - Хорьков Д.А\\testDynamic1\\testDynamic1\\DynamicLib.dll");
    if(hDll == NULL)
        std::cout << "Could not load the DLL \n";
    else
    {
        group* MyGroup;
        name* MyName;
        MyGroup = (group*)GetProcAddress(hDll, "MyGroup");
        MyName = (name*)GetProcAddress(hDll, "MyName");

        std::cout << "My group is " << MyGroup(571227) << "\n";
        char myname[20];
        MyName(myname);
        std::cout << "My name is " << myname << "\n";
        system("pause");
    }
    FreeLibrary(hDll);
    return 0;
}

