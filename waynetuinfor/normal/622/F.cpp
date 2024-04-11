#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5, mod = 1e9 + 7;
int f[maxn], p[maxn], invp[maxn];

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

int calc(int l, int r) {
    if (l > 0) return p[r] * 1ll * invp[l - 1] % mod;
    int x = p[r], y = p[-l];
    if (l & 1) y = mod - y;
    return x * 1ll * y % mod;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= k + 2; ++i) f[i] = (f[i - 1] + fpow(i, k)) % mod;
    if (n <= k + 2) return 0 * printf("%d\n", f[n]);
    p[0] = 1; invp[0] = 1;
    for (int i = 1; i <= k + 2; ++i) p[i] = p[i - 1] * 1ll * i % mod, invp[i] = fpow(p[i], mod - 2);
    int fn = 0, z = 1;
    for (int i = 1; i <= k + 2; ++i) z = z * 1ll * (n - i) % mod;
    for (int i = 1; i <= k + 2; ++i) {
         int coef = z * 1ll * fpow(n - i, mod - 2) % mod;
         coef = coef * 1ll * fpow(calc(i - (k + 2), i - 1), mod - 2) % mod;
         fn = (fn + coef * 1ll * f[i] % mod) % mod;
    }
    printf("%d\n", fn);
    return 0;
}