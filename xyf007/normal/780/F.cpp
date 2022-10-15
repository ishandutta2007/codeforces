#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <bitset>
int n, m;
std::bitset<501> dp[2][64][501];
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        dp[c][0][u].set(v);
    }
    for (int l = 1; l <= 60; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[0][l - 1][i].test(j))
                {
                    dp[0][l][i] |= dp[1][l - 1][j];
                }
                if (dp[1][l - 1][i].test(j))
                {
                    dp[1][l][i] |= dp[0][l - 1][j];
                }
            }
        }
    }
    long long ans = 0LL;
    std::bitset<501> now, pre;
    int op = 0;
    pre.set(1);
    for (int i = 60; i >= 0; i--)
    {
        now.reset();
        for (int j = 1; j <= n; j++)
        {
            if (pre.test(j))
            {
                now |= dp[op][i][j];
            }
        }
        if (now.any())
        {
            op ^= 1;
            pre = now;
            ans += 1LL << i;
        }
    }
    if (ans > 1000000000000000000)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }
    return 0;
}