#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;
const int MOD = (int)1e6 + 3;

int mul(int a, int b)
{
    return (ll)a * b % MOD;
}

int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int bin_pow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

int mod_inv(int a)
{
    return bin_pow(a, MOD - 2);
}

int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = mul(res, i);
    return res;
}

void solve()
{
    int n, c;
    scanf("%d%d", &n, &c);

    int ans = fact(n + c);
    ans = mul(ans, mod_inv(fact(n)));
    ans = mul(ans, mod_inv(fact(c)));
    ans = sub(ans, 1);

    printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}