#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int mod = 1e9 + 7, inv2 = (mod + 1) >> 1;

int n, m; char a[22][100100];
int b[1 << 20];

int N;
void XOR (int *f) {
    for (int i = 2; i <= N; i <<= 1)
        for (int j = 0; j < N; j += i)
            for (int k = j; k < j + (i >> 1); k++) {
                int u = f[k], v = f[k + (i >> 1)];
                f[k] = (u + v) % mod, f[k + (i >> 1)] = (u - v) % mod;
            }
}

void IXOR (int *f) {
    for (int i = 2; i <= N; i <<= 1)
        for (int j = 0; j < N; j += i)
            for (int k = j; k < j + (i >> 1); k++) {
                int u = f[k], v = f[k + (i >> 1)];
                u = 1ll * u * inv2 % mod, v = 1ll * v * inv2 % mod;
                f[k] = (u + v) % mod, f[k + (i >> 1)] = (u - v) % mod;
            }
}

int p[1 << 20];

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (i = 1; i <= m; i++) {
        int now = 0;
        for (j = 1; j <= n; j++) now = (now << 1) | (a[j][i] == '1');
        ++b[now];
    }
    N = 1 << n;
    for (i = 0; i < N; i++) p[i] = min(__builtin_popcount(i), __builtin_popcount((N - 1) ^ i));
    XOR(b), XOR(p);
    for (i = 0; i < N; i++) b[i] = 1ll * b[i] * p[i] % mod;
    IXOR(b);
    int ans = mod;
    for (i = 0; i < N; i++) ans = min(ans, (b[i] + mod) % mod);
    printf("%d\n", ans);
    return 0;
}