#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int readbin() {
    int ret = 0; char c = getchar();
    while (c != '0' && c != '1') c = getchar();
    while (c == '0' || c == '1') ret = ret << 1 | (c - '0'), c = getchar();
    return ret;
}
inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1 << 20;
using pii = pair <int, int>;
#define fr first
#define se second

int n, m, K, A, B; pii a[MAXN];
int p[22];
int pc(int x) { return __builtin_popcount(x); }
void chkmax(int &u, int v) { u = max(u, v); }
void chkmin(int &u, int v) { u = min(u, v); }

int f[MAXN], g[MAXN];

int main() {
    n = read(), m = read(), K = read();
    A = readbin(), B = readbin();
    int i, j, k;
    for (i = 1; i <= n; i++) a[i].fr = K - read(), a[i].se = K - read();
    for (i = 0; i < K; i++) p[i] = i;
    memset(f, 0x3f, sizeof f);
    chkmax(g[B], n + 1);
    for (i = n; i >= 1; i--) {
        for (j = 0; j < K; j++) if (p[j] == a[i].fr || p[j] == a[i].se) p[j] ^= a[i].fr ^ a[i].se;
        int pA = 0, pB = 0;
        for (j = 0; j < K; j++) pA += ((A >> p[j]) & 1) << j, pB += ((B >> p[j]) & 1) << j;
        chkmin(f[pA], i), chkmax(g[pB], i);
    }
    for (i = 2; i <= (1 << K); i <<= 1)
        for (j = 0; j < (1 << K); j += i)
            for (k = j; k < j + (i >> 1); k++)
                chkmin(f[k], f[k + (i >> 1)]), chkmax(g[k], g[k + (i >> 1)]);
    int l, r, ans = -1;
    for (i = 0; i < (1 << K); i++) if (g[i] - f[i] >= m) {
        if (ans < pc(i)) ans = pc(i), l = f[i], r = g[i] - 1;
    }
    printf("%d\n", ans * 2 + (K - pc(B)) - pc(A));
    printf("%d %d\n", l, r);
    return 0;
}