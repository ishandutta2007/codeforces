#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
char s[201][201];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> (s[i] + 1);
        }
        if (s[1][2] == s[2][1])
        {
            if (s[n - 1][n] == s[n][n - 1])
            {
                if (s[1][2] == s[n - 1][n])
                {
                    cout << "2\n"
                         << n - 1 << ' ' << n << '\n'
                         << n << ' ' << n - 1 << '\n';
                }
                else
                {
                    cout << "0\n";
                }
            }
            else
            {
                if (s[n - 1][n] == s[1][2])
                {
                    cout << "1\n"
                         << n - 1 << ' ' << n << '\n';
                }
                else
                {
                    cout << "1\n"
                         << n << ' ' << n - 1 << '\n';
                }
            }
        }
        else
        {
            if (s[n - 1][n] == s[n][n - 1])
            {
                if (s[n - 1][n] == s[1][2])
                {
                    cout << "1\n1 2\n";
                }
                else
                {
                    cout << "1\n2 1\n";
                }
            }
            else
            {
                if (s[1][2] == s[n][n - 1])
                {
                    cout << "2\n1 2\n"
                         << n - 1 << ' ' << n << '\n';
                }
                else
                {
                    cout << "2\n1 2\n"
                         << n << ' ' << n - 1 << '\n';
                }
            }
        }
    }
    return 0;
}