#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
     string str;
     cin >> str;
     int a;
     cin >> a;
    if ((a==1&&str=="front")||(a==2&&str=="back"))
    {
        cout << "L";
    }
    else
        cout << "R";
    return 0;
}