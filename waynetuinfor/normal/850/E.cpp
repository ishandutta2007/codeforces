#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
const long long mod = 1e9 + 7, inv = 500000004;
char s[(1 << maxn) + 1];
long long v[1 << maxn];

void fwt(long long *v, int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) >> 1;
    fwt(v, l, m), fwt(v, m, r);
    for (int i = l, j = m; i < m; ++i, ++j) {
        long long x = (v[i] + v[j]) % mod;
        v[j] = (v[i] - v[j] + mod) % mod;
        v[i] = x;
    }
}

void ifwt(long long *v, int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) >> 1;
    for (int i = l, j = m; i < m; ++i, ++j) {
        long long x = (v[i] + v[j]) * inv % mod;
        v[j] = (v[i] - v[j] + mod) * inv % mod;
        v[i] = x;
    }
    ifwt(v, l, m), ifwt(v, m, r);
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < (1 << n); ++i) v[i] = s[i] - '0';
    fwt(v, 0, (1 << n));
    for (int i = 0; i < (1 << n); ++i) (v[i] *= v[i]) %= mod;
    ifwt(v, 0, (1 << n));
    long long ans = 0;
    for (int i = 0; i < (1 << n); ++i) (ans += v[i] * (1 << (n - __builtin_popcount(i))) % mod) %= mod;
    (ans *= 3) %= mod;
    printf("%lld\n", ans);
    return 0;
}