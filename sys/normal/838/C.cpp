#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 19 | 5;
int n, k, p, maxi, ct[Maxn], f[Maxn];
int tmp1[20][Maxn], tmp2[20][Maxn], tmp3[20][Maxn];
long long pp;
long long t[20][Maxn];
long long fac[Maxn], inv[Maxn];
long long fast_pow(long long x, long long y)
{
    long long ans = 1, now = x;
    while (y)
    {
        if (y & 1) ans = ans * now % p;
        now = now * now % p;
        y >>= 1;
    }
    return ans;
}
void init(void)
{
    fac[0] = 1;
    for (int i = 1; i <= maxi; i++)
        fac[i] = fac[i - 1] * i % p;
    inv[maxi] = fast_pow(fac[maxi], p - 2);
    for (int i = maxi - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}
int lower(int x)
{
    int tmp = 1;
    for (; tmp < x; tmp <<= 1);
    return tmp;
}
void FWT(int *now, int len, bool type = false)
{
    long long *T = t[0];
    for (int i = 0; i < len; i ++) T[i] = now[i];
    if (type)
        for (int i = 1; i < len; i <<= 1)
            for (int j = 0; j < len; j += (i << 1))
                for (int k = j; k < i + j; k++)
                    T[i + k] -= T[k];
    else
        for (int i = 1; i < len; i <<= 1)
            for (int j = 0; j < len; j += (i << 1))
                for (int k = j; k < i + j; k++)
                    T[i + k] += T[k];
    for (int i = 0; i < len; i ++) {
        now[i] = T[i] % p;
        if (now[i] < 0) now[i] += p;
    }
}
inline void __a (long long &x) { x >= pp ? x -= pp : x; }
void multi(void)
{
    for (int j = 0; j <= 19; j++)
    {
        memset(tmp1[j], 0, sizeof(int[maxi + 1]));
        memset(t[j], 0, sizeof(long long[maxi + 1]));  
    }
    for (int j = 0; j <= maxi; j++)
        tmp1[ct[j]][j] = f[j];
    for (int j = 0; j <= 19; j++)
        FWT(tmp1[j], maxi + 1);
    for (int q = 0; q <= 19; q++)
        for (int l = 0; q + l <= 19; l++)
            for (int s = 0; s <= maxi; s++)
                __a(t[q + l][s] += 1ll * tmp1[q][s] * tmp2[l][s]);
    for (int q = 0; q <= 19; q++)
        for (int s = 0; s <= maxi; s++)
            tmp3[q][s] = t[q][s] % p;
    for (int j = 0; j <= 19; j++)
        FWT(tmp3[j], maxi + 1, true);
    for (int j = 0; j <= maxi; j++)
        f[j] = tmp3[ct[j]][j];
}
void multi2(void)
{
    static int tmp[20][Maxn];
    for (int i = 0; i <= 19; i++)
        memset(t[i], 0, sizeof(long long[maxi + 1]));
    for (int q = 0; q <= 19; q++)
        for (int l = 0; q + l <= 19; l++)
            for (int s = 0; s <= maxi; s++)
                __a(t[q + l][s] += 1ll * tmp2[q][s] * tmp2[l][s]);
    for (int q = 0; q <= 19; q++)
        for (int s = 0; s <= maxi; s++)
            tmp[q][s] = t[q][s] % p;
    for (int i = 0; i <= 19; i++)
        FWT(tmp[i], maxi + 1, true);
    for (int i = 0; i <= 19; i++)
        memset(tmp2[i], 0, sizeof(int[maxi + 1]));
    for (int i = 0; i <= maxi; i++)
        tmp2[ct[i]][i] = tmp[ct[i]][i];
    for (int i = 0; i <= 19; i++)
        FWT(tmp2[i], maxi + 1);
}
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    pp = 1ll * p * p;
    if (n & 1)
    {
        printf("%lld", fast_pow(k, n));
        return 0;
    }
    f[0] = 1;
    maxi = lower(n + 1) - 1;
    init();
    for (int i = 0; i <= maxi; i++)
        ct[i] = __builtin_popcount(i);
    for (int i = 0; i <= maxi; i++)
        tmp2[ct[i]][i] = inv[i];
    for (int i = 0; i <= 19; i++)
        FWT(tmp2[i], maxi + 1);
    int res_k = k;
    while (k)
    {
        cerr << k << endl;
        if (k & 1) multi();
        k >>= 1;
        if (k) multi2();
    }
    printf("%lld", (fast_pow(res_k, n) - fac[n] * f[n] % p + p) % p);
    return 0;
}