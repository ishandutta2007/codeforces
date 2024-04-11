#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5, mod = 1e9 + 7;
int fac[maxn], invf[maxn];

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1, a = a * 1ll * a % mod) if (n & 1) r = r * 1ll * a % mod;
    return r;
}

int comb(long long n, long long k) {
    if (n < k) return 0;
    if (n < 0) return 0;
    if (k < 0) return 0;
    return fac[n] * 1ll * invf[k] % mod * 1ll * invf[n - k] % mod;
}

int split(int p, int t, int h) {
    if (t == 0 && p == 0) return 1;
    long long n = t, k = p - t * 1ll * h;
    return comb(n + k - 1, k);     
}

int main() {
    fac[0] = invf[0] = 1;
    for (int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * 1ll * i % mod, invf[i] = fpow(fac[i], mod - 2);
    int f, w, h; scanf("%d %d %d", &f, &w, &h);
    int q = 0;
    for (int i = 1; i <= f + w; ++i) {
        int a = i / 2, b = i - a;
        q = (q + split(f, a, 1) * 1ll * split(w, b, 1) % mod) % mod;
        q = (q + split(w, a, 1) * 1ll * split(f, b, 1) % mod) % mod;
    }   
    int p = 0;
    for (int i = 1; i <= f + w; ++i) {
        int a = i / 2, b = i - a;
        p = (p + split(f, a, 1) * 1ll * split(w, b, h + 1) % mod) % mod;
        p = (p + split(w, a, h + 1) * 1ll * split(f, b, 1) % mod) % mod;
    }
    p = p * 1ll * fpow(q, mod - 2) % mod;
    printf("%d\n", p);
    return 0;
}