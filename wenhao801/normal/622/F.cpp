#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000, mod = 1e9 + 7;
int qpow (int x, int y) {
    if (y < 0) return qpow(qpow(x, -y), mod - 2);
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int k, n;
int FAC[MAXN], pre[MAXN], suf[MAXN];
int fac (int x) { return (x < 0 && (x & 1)) ? -FAC[-x] : FAC[abs(x)]; }

int main () {
    k = read(), n = read();
    int i, j; FAC[0] = pre[0] = 1, suf[n + 3] = 1;
    for (i = 1; i <= n + 2; i++) FAC[i] = 1ll * FAC[i - 1] * i % mod, pre[i] = 1ll * pre[i - 1] * (k - i) % mod;
    for (i = n + 2; i >= 0; i--) suf[i] = 1ll * suf[i + 1] * (k - i) % mod;
    int Y = 0, ans = 0;
    for (i = 1; i <= n + 2; i++) {
        Y = (Y + qpow(i, n)) % mod;
        int tmp = 1ll * Y * pre[i - 1] % mod * suf[i + 1] % mod * qpow(fac(i - 1), -1) % mod * qpow(fac(i - n - 2), -1) % mod;
        ans = (ans + tmp) % mod;
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}