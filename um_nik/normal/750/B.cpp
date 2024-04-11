#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int x = 0;
    int n;
    string s;
    int y;
    cin >> n;
    while(n--)
    {
        cin >> y >> s;
        if (x == 0)
        {
            if (s != "South")
            {
                cout << "NO" << endl;
                return 0;
            }
            x += y;
        }
        else if (x == 20000)
        {
            if (s != "North")
            {
                cout << "NO" << endl;
                return 0;
            }
            x -= y;
        }
        else if (s == "North")
        {
            x -= y;
        }
        else if (s == "South")
        {
            x += y;
        }
        if (x < 0 || x > 20000)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (x == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}