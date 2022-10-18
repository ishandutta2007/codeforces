#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll T, x, y, c[15];
void checkmin(ll &x, ll y)
{
    x = (x < y) ? x : y;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> x >> y;
        for (int i = 1; i <= 6; i++)
        {
            cin >> c[i];
        }
        checkmin(c[1], c[2] + c[6]);
        checkmin(c[2], c[1] + c[3]);
        checkmin(c[3], c[2] + c[4]);
        checkmin(c[4], c[3] + c[5]);
        checkmin(c[5], c[4] + c[6]);
        checkmin(c[6], c[1] + c[5]);
        if (x <= 0 && y >= 0)
        {
            cout << (-x) * c[3] + y * c[2] << '\n';
        }
        else if (x >= 0 && y <= 0)
        {
            cout << x * c[6] + (-y) * c[5] << '\n';
        }
        else
        {
            if (x < 0)
            {
                x = -x, y = -y;
                if (c[4] >= c[3] + c[5])
                {
                    cout << x * c[3] + y * c[5] << '\n';
                }
                else
                {
                    ll res = min(x, y) * c[4];
                    ll cur = min(x, y);
                    x -= cur, y -= cur;
                    cout << x * c[3] + y * c[5] + res << '\n';
                }
            }
            else
            {
                if (c[1] >= c[2] + c[6])
                {
                    cout << x * c[6] + y * c[2] << '\n';
                }
                else
                {
                    ll res = min(x, y) * c[1];
                    ll cur = min(x, y);
                    x -= cur, y -= cur;
                    cout << x * c[6] + y * c[2] + res << '\n';
                }
            }
        }
    }
    return 0;
}