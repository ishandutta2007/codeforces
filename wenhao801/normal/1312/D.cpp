#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

const int mod = 998244353;
int n, m;

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

const int MAXN = 200200;

int fac[MAXN], invfac[MAXN];
int pow2[MAXN];

int C (int x, int y) { if (x < y) return 0; return fac[x] * invfac[y] % mod * invfac[x - y] % mod; }

signed main () {
    pow2[0] = fac[0] = invfac[0] = 1;
    scanf("%lld%lld", &n, &m);
    if (n == 2) {
        puts("0");
        return 0;
    }
    int i, j;
    int ans = 0;
    for (i = 1; i <= m; i++) fac[i] = fac[i - 1] * i % mod, invfac[i] = inv(fac[i]), pow2[i] = pow2[i - 1] * 2 % mod;
    //for (i = 1; i <= n; i++) cout << fac[i] << ' ' << invfac[i] << endl;
    for (i = 1; i <= m; i++) {
        ans = (ans + C(i - 1, n - 2) * (n - 2) % mod * pow2[n - 3] % mod) % mod;
        //cout << ans << endl;
    }
    printf("%lld\n", ans);
    return 0;
}