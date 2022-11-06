#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
int fc[maxn], iv[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

int cnk(int n, int k) {
    if (n < k) return 0;
    return fc[n] * 1ll * iv[k] % mod * iv[n - k] % mod;
}

int main() {
    int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
    fc[0] = iv[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fc[i] = fc[i - 1] * 1ll * i % mod;
        iv[i] = fpow(fc[i], mod - 2);
    }
    int ans = 0;
    for (int d = 1; d <= min(n - 1, m); ++d) {
        int p = cnk(n - 2, d - 1) * 1ll * fc[d - 1] % mod * cnk(m - 1, d - 1) % mod;
        if (d == n - 1) {
            ans += p;
            ans %= mod;
            continue;
        }
        int t = (d + 1) * 1ll * fpow(n, n - d - 2) % mod;
        int e = fpow(m, n - 1 - d);
        ans += p * 1ll * t % mod * e % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}