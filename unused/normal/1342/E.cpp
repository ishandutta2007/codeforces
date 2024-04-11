#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int fact[200005];
int finv[200005];

int fastpow(int x, int y)
{
        if (y == 0) return 1;
        if (y & 1) return fastpow(x, y - 1) * 1ll * x % MOD;
        int z = fastpow(x, y / 2);
        return z * 1ll * z % MOD;
}

int comb(int x, int y)
{
        return fact[x] * 1ll * finv[y] % MOD * finv[x - y] % MOD;
}

// y from [1, x]
int calc(int x, int y)
{
        int ret = 0;

        for (int i = 0; i < x; i++)
        {
                int c = comb(x, i) * 1ll * fastpow(x - i, y) % MOD;
                if (i & 1) ret = (ret + MOD - c) % MOD;
                else ret = (ret + c) % MOD;
        }

        return ret;
}

int main()
{
        fact[0] = 1;
        for (int i = 1; i <= 200000; i++) fact[i] = fact[i - 1] * 1ll * i % MOD;
        finv[200000] = 532999597;
        for (int i = 199999; i >= 0; i--) finv[i] = finv[i + 1] * 1ll * (i + 1) % MOD;
        assert(finv[0] == 1);

        int n;
        long long k;
        scanf("%d%lld",&n,&k);
        if (k == 0)
        {
                int ans = 1;
                for (int i = 2; i <= n; i++) ans = ans * 1ll * i % MOD;
                printf("%d\n", ans);
        }
        else if (k >= n)
        {
                printf("0\n");
        }
        else
        {
                printf("%d\n", (int)(comb(n, k) * 2ll * calc(n - k, n) % MOD));
        }
}