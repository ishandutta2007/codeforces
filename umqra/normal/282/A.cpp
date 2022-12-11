#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    string str;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int t = 0;
        for (int s = 0; s < (int)str.length(); s++)
        {
            if (str[s] == '+')
                t = 1;
            else if (str[s] == '-')
                t = -1;
        }
        x += t;
    }

    cout << x;

    return 0;
}