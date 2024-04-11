#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n < 3 || n == 4)
        {
            cout << "-1\n";
            continue;
        }
        if ((!(n % 3)))
        {
            cout << n / 3 << " 0 0\n";
        }
        else
        {
            if (n % 3 == 1)
            {
                cout << n / 3 - 2 << " 0 1\n";
            }
            else
            {
                cout << n / 3 - 1 << " 1 0\n";
            }
        }
    }
    return 0;
}