#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 2520;
long long t, Hash[2521], bit[20], g[2521][10], dp[20][50][2521];
void init()
{
    int tmp = 0;
    for (int i = 1; i <= MOD; i++)
    {
        if (!(MOD % i))
        {
            Hash[i] = ++tmp;
        }
    }
    for (int i = 1; i <= MOD; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j)
            {
                g[i][j] = i * j / __gcd(i, j);
            }
            else
            {
                g[i][j] = i;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
}
long long dfs(long long len, long long num, long long lcm, bool less)
{
    if (!len)
    {
        return !(num % lcm);
    }
    if (!less && dp[len][Hash[lcm]][num] != -1)
    {
        return dp[len][Hash[lcm]][num];
    }
    long long sum = 0, maxx;
    if (less)
    {
        maxx = bit[len];
    }
    else
    {
        maxx = 9;
    }
    for (int i = 0; i <= maxx; i++)
    {
        sum += dfs(len - 1, (num * 10 + i) % MOD, g[lcm][i], less && (i == maxx));
    }
    if (!less)
    {
        dp[len][Hash[lcm]][num] = sum;
    }
    return sum;
}
long long query(long long x)
{
    int tmp = 0;
    while (x)
    {
        bit[++tmp] = x % 10;
        x /= 10;
    }
    return dfs(tmp, 0, 1, 1);
}
int main(int argc, char const *argv[])
{
    init();
    scanf("%lld", &t);
    while (t--)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", query(r) - query(l - 1));
    }
    return 0;
}