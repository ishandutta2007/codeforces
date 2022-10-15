#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long MOD = 1e9 + 7;
int t, n;
long long dp[2000001];
void init()
{
    dp[3] = 4;
    for (int i = 4; i <= 2000000; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2] + !(i % 3) * 4) % MOD;
    }
}
int main(int argc, char const *argv[])
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", dp[n] % MOD);
    }
    return 0;
}