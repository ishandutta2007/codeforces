#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int ppp, qqq; char buf[1 << 20];
inline char gc () {
    if (ppp == qqq) ppp = 0, qqq = fread(buf, 1, 1 << 20, stdin);
    return buf[ppp++];
}
#define getchar gc

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
const int MAXN = 1001000, LIM = 1e6, mod = 1e9 + 7;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int p[MAXN]; bool np[MAXN];
void genp () {
    int i, j;
    for (i = 2; i <= LIM; i++) {
        if (!np[i]) p[++p[0]] = i;
        for (j = 1; j <= p[0]; j++) {
            if (p[j] * i > LIM) break;
            np[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
int cnt[200200][169];
struct Query { int l, r, id; bool operator < (const Query &x) const { return r < x.r; } } Q[MAXN];
int n, q, a[MAXN], ans[MAXN];
int las[MAXN];

int t[MAXN];
inline int lowbit (int x) { return x & -x; }
inline void modify (int x, int k) { while (x <= n) t[x] = 1ll * t[x] * k % mod, x += lowbit(x); }
inline int query (int x) { int ret = 1; while (x) ret = 1ll * ret * t[x] % mod, x -= lowbit(x); return ret; }

int main () {
    genp();
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    q = read();
    for (i = 1; i <= q; i++) Q[i].l = read(), Q[i].r = read(), Q[i].id = i;
    sort(Q + 1, Q + q + 1);
    for (i = 1; i <= 168; i++) cnt[0][i] = 1;
    for (i = 1; i <= n; i++) {
        t[i] = 1;
        for (j = 1; j <= 168; j++) cnt[i][j] = 1;
    }
    int now = 1;
    for (i = 1; i <= n; i++) {
        int x = a[i];
        for (j = 1; j <= 168; j++) {
            cnt[i][j] = cnt[i - 1][j];
            while (x % p[j] == 0) cnt[i][j] = 1ll * cnt[i][j] * p[j] % mod, x /= p[j];
        }
        if (x != 1) {
            if (las[x]) modify(las[x], 1ll * x * inv(x - 1) % mod);
            modify(i, x - 1); las[x] = i;
        }
        while (now <= q && Q[now].r == i) {
            ans[Q[now].id] = 1; int invtmp = 1;
            for (j = 1; j <= 168; j++) {
                if (cnt[i][j] == cnt[Q[now].l - 1][j]) continue;
                ans[Q[now].id] = 1ll * ans[Q[now].id] * cnt[i][j] % mod * (p[j] - 1) % mod;
                invtmp = 1ll * invtmp * cnt[Q[now].l - 1][j] % mod * p[j] % mod;
                // printf("%d %d\n", ans[Q[now].id], invtmp);
            }
            ans[Q[now].id] = 1ll * ans[Q[now].id] * query(Q[now].r) % mod * inv(query(Q[now].l - 1)) % mod;
            ans[Q[now].id] = 1ll * ans[Q[now].id] * inv(invtmp) % mod;
            ++now;
        }
    }
    for (i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}