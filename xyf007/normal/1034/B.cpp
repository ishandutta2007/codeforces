#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (n > m)
    {
        swap(n, m);
    }
    if (n == 1)
    {
        cout << m / 6 * 6 + 2 * max(m % 6 - 3, 0);
        return 0;
    }
    if (n == 2)
    {
        if (m == 2)
        {
            cout << 0;
        }
        else
        {
            if (m == 3)
            {
                cout << 4;
            }
            else
            {
                if (m == 7)
                {
                    cout << 12;
                }
                else
                {
                    cout << n * static_cast<long long>(m);
                }
            }
        }
    }
    else
    {
        cout << n * static_cast<long long>(m) / 2 * 2;
    }
    return 0;
}