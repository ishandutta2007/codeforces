#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll poww(ll a, ll b)
{
    if(b == 0) return 1;
    if(b & 1) return a * poww(a, b - 1) % mod;
    return poww(a * a % mod, b / 2);
}

ll inv(ll a)
{
    return poww(a, mod - 2);
}

const int K = 5001;
ll fac[K];
ll facinv[K];
ll powk[K];

ll newton(ll a, ll b)
{
    return fac[a] * facinv[b] % mod * facinv[a - b] % mod;
}

ll f(int i)
{
    ll ans = 0;
    for(int j = 0, s = 1; j < i; j++, s = -s)
        ans += powk[i-j] * newton(i, j) * s % mod;
    return ans % mod;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    fac[0] = facinv[0] = 1;
    for(int i = 1; i <= k; i++)
    {
        fac[i] = fac[i-1] * i % mod;
        facinv[i] = inv(fac[i]);
        powk[i] = poww(i, k);
    }
    ll ans = 0, newt = 1, pow2 = poww(2, n), inv2 = inv(2);
    for(int i = 1; i <= min(n, k); i++)
    {
        newt = newt * (n - i + 1) % mod * inv(i) % mod;
        pow2 = pow2 * inv2 % mod;
        ans += newt * f(i) % mod * pow2 % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    printf("%lld\n", ans);
}