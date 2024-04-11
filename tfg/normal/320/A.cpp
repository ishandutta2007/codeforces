#include <iostream>
#include <string>

int main()
{
    std::string str;
    int got=0;
    bool valid=true;
    std::cin >> str;
    if(str[0]!='1')
        valid=false;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='1')
            got=0;
        else if(str[i]=='4')
            got++;
        else
            valid=false;
        if(got>2)
            valid=false;
    }
    if(valid)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}