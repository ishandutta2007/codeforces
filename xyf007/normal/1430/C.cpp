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
        if (n == 2)
        {
            cout << "2\n2 1\n";
            continue;
        }
        cout << "2\n"
             << n << ' ' << n - 2 << '\n'
             << n - 1 << ' ' << n - 1 << '\n';
        for (int i = n - 1; i >= 3; i--)
        {
            cout << i << ' ' << i - 2 << '\n';
        }
    }
    return 0;
}