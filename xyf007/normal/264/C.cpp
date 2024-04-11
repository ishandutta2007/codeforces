#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, q, v[100001], c[100001];
long long dp[100001];
void checkmax(long long &x, long long y)
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
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    while (q--)
    {
        int a, b, c1 = 0, c2 = 0;
        long long tmp, ans = 0;
        cin >> a >> b;
        memset(dp, 0xcf, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            tmp = max(dp[c[i]] + a * static_cast<long long>(v[i]), max(c1 == c[i] ? dp[c2] : dp[c1], 0LL) + b * static_cast<long long>(v[i]));
            if (tmp > dp[c1])
            {
                if (c[i] != c1)
                {
                    c2 = c1;
                    c1 = c[i];
                }
            }
            else
            {
                if (tmp > dp[c2] && c[i] != c1)
                {
                    c2 = c[i];
                }
            }
            checkmax(dp[c[i]], tmp);
            checkmax(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}