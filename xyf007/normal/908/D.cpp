#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;
int ksm(int a, int b)
{
    int s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = 1LL * s * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return s;
}
int k, pa, pb, A, B, C, dp[1001][1001];
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &k, &pa, &pb);
    A = 1LL * pa * ksm(pa + pb, MOD - 2) % MOD;
    B = 1LL * pb * ksm(pa + pb, MOD - 2) % MOD;
    C = 1LL * pa * ksm(pb, MOD - 2) % MOD;
    for (int i = k; i >= 1; i--)
    {
        for (int j = k; j >= 0; j--)
        {
            if (i + j >= k)
            {
                dp[i][j] = (i + j + C) % MOD;
            }
            else
            {
                dp[i][j] = (1LL * A * dp[i + 1][j] + 1LL * B * dp[i][i + j]) % MOD;
            }
        }
    }
    printf("%d", dp[1][0]);
    return 0;
}