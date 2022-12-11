#include <cstdio>
using namespace std;

constexpr int MOD = (int)1e9 + 7;

long long dat[500005];

void proc()
{
    int n;
    scanf("%d", &n);

    int flagsum[64] = {};
    int flagcnt[64] = {};
    int flagandsum[64] = {};
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        long long x;
        scanf("%lld", &x);

        dat[i] = x;

        sum = (sum + x) % MOD;

        for (long long j = x; j; j -= j & -j)
        {
            int idx = 63 - __builtin_clzll(j & -j);
            flagcnt[idx]++;
            flagsum[idx] = (flagsum[idx] + x) % MOD;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (long long j = dat[i]; j; j -= j & -j)
        {
            int idx = 63 - __builtin_clzll(j & -j);
            s = (s + flagcnt[idx] * ((j & -j) % MOD) % MOD) % MOD;
        }

        for (long long j = dat[i]; j; j -= j & -j)
        {
            int idx = 63 - __builtin_clzll(j & -j);
            flagandsum[idx] = (flagandsum[idx] + s) % MOD;
        }
    }

    int ans2 = 0;
    for (int i = 0; i < 60; i++) ans2 = (ans2 + ((1LL << i) % MOD) * ((flagcnt[i] * 1ll * flagcnt[i] % MOD * sum + flagcnt[i] * 1ll * n % MOD * flagsum[i]) % MOD)) % MOD;

    for (int i = 0; i < 60; i++) ans2 = ((ans2 - ((1LL << i) % MOD) * ((flagcnt[i] * 1ll * flagandsum[i]) % MOD)) % MOD + MOD) % MOD;

    printf("%d\n", ans2);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        proc();
    }
}