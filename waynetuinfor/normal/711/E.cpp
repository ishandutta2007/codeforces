#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 3;

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1, a = a * 1ll * a % mod) if (n & 1) r = r * 1ll * a % mod;
    return r;
}

int main() {
    long long n, k; scanf("%lld %lld", &n, &k);
    if (n <= 60 && k > (1ll << n)) return 0 * puts("1 1");
    int q = fpow(2, ((n % (mod - 1)) * 1ll * ((k - 1) % (mod - 1))) % (mod - 1));
    int p = 0, t = fpow(2, n % (mod - 1));
    if (k < mod) {
        p = 1;
        for (int i = 1; i < k; ++i) p = p * 1ll * (t - i + mod) % mod;
    }
    long long tpow = 0;
    for (long long r = 2; (k - 1) / r > 0; r *= 2) tpow += (k - 1) / r;
    tpow = fpow(2, tpow % (mod - 1));
    p = p * 1ll * fpow(tpow, mod - 2) % mod;
    q = q * 1ll * fpow(tpow, mod - 2) % mod;
    p = (q - p + mod) % mod;
    printf("%d %d\n", p, q);
    return 0;
}