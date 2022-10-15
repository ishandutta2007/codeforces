#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k, a[100001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int x, tmp = 0, ans = 0, l = 1;
        bool f = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            f |= x == k;
            a[i] = 1 - 2 * (x < k);
        }
        if (!f)
        {
            cout << "no\n";
            continue;
        }
        if (n == 1)
        {
            cout << "yes\n";
            continue;
        }
        f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (tmp < 0)
            {
                tmp = 0;
                l = i;
            }
            tmp += a[i];
            if (i - l)
            {
                checkmax(ans, tmp);
                if (ans > 0)
                {
                    f = 1;
                    cout << "yes\n";
                    break;
                }
            }
        }
        if (!f)
        {
            cout << "no\n";
        }
    }
    return 0;
}