#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;
int f[maxn], inv[maxn];

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
    return f[n] * 1ll * inv[k] % mod * inv[n - k] % mod;
}

int g(int n, int i, int j) {
    if (i == 0) return fpow(3, j) * 1ll * fpow(3, n * 1ll * (n - j) % (mod - 1)) % mod;
    if (j == 0) return fpow(3, i) * 1ll * fpow(3, n * 1ll * (n - i) % (mod - 1)) % mod;
    return 3ll * fpow(3, (n - i) * 1ll * (n - j) % (mod - 1)) % mod;
}

int main() {
    int n; scanf("%d", &n);
    f[0] = inv[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = f[i - 1] * 1ll * i % mod;
        inv[i] = fpow(f[i], mod - 2);
    }
    int ans = 0;
    int x = 0;
    for (int i = 0, j = mod - 1; i < n; ++i, j = mod - j) {
        int y = cnk(n, i) * 1ll * j % mod;
        int z = fpow((fpow(3, i) + mod - 1) % mod, n);
        z += mod - fpow(3, n * 1ll * i % (mod - 1)) % mod;
        if (n & 1) z = z * 1ll * (mod - 1) % mod;
        ans += y * 1ll * z % mod;
        ans %= mod;
    } 
    ans = ans * 3ll % mod;
    for (int i = 0; i <= n; ++i) {
        if (i == 0) continue;
        int comb = cnk(n, i) * 1ll * cnk(n, 0) % mod;
        comb = comb * 1ll * g(n, i, 0) % mod;
        comb = comb * 2ll % mod;
        if (i & 1) (ans += comb) %= mod;
        else (ans += mod - comb) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}