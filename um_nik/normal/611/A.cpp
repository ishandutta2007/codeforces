#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int x;
    string s;
    cin >> x >> s >> s;

    if (s == "week")
    {
        if (x == 5 || x == 6)
            cout << 53 << endl;
        else
            cout << 52 << endl;
    }
    else
    {
        if (x == 31)
            cout << 7 << endl;
        else if (x == 30)
            cout << 11 << endl;
        else
            cout << 12 << endl;
    }

    return 0;
}