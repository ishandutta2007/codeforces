#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int mod1 = 19260817, mod2 = 1e8 + 7, mul = 31, MAXN = 600600;
int qpow (int x, int y, int mod) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}
vector <int> E[MAXN]; int n, q;
char val[MAXN];
int pow1[MAXN] = {1}, pow2[MAXN] = {1}, ipow1[MAXN] = {1}, ipow2[MAXN] = {1};
int pre1[MAXN], pre2[MAXN], suf1[MAXN], suf2[MAXN];

int fa[MAXN][22], lg2[MAXN], dep[MAXN], siz[MAXN], wson[MAXN];
void dfs1 (int x, int f) {
    fa[x][0] = f, siz[x] = 1, dep[x] = dep[f] + 1;
    pre1[x] = (1ll * mul * pre1[f] % mod1 + val[x] - 'a') % mod1;
    pre2[x] = (1ll * mul * pre2[f] % mod2 + val[x] - 'a') % mod2;
    suf1[x] = (1ll * pow1[dep[x] - 1] * (val[x] - 'a') % mod1 + suf1[f]) % mod1;
    suf2[x] = (1ll * pow2[dep[x] - 1] * (val[x] - 'a') % mod2 + suf2[f]) % mod2;
    for (int i = 1, j = fa[x][0]; i <= 20 && j; ++i) fa[x][i] = j = fa[j][i - 1];
    for (auto i: E[x]) if (i != f) {
        dfs1(i, x); siz[x] += siz[i];
        if (siz[i] > siz[wson[x]]) wson[x] = i;
    }
}
struct kth_ancestor {
    int top[MAXN], lson[MAXN], mdep[MAXN], cnt;
    vector <int> u[MAXN], d[MAXN];

    void dfs1 (int x, int f) {
        mdep[x] = dep[x];
        for (auto i: E[x]) if (i != f) {
            dfs1(i, x);
            if (mdep[i] > mdep[x]) lson[x] = i, mdep[x] = mdep[i];
        }
    }
    void dfs2 (int x) {
        if (lson[x]) top[lson[x]] = top[x], dfs2(lson[x]);
        for (auto i: E[x]) {
            if (i == lson[x] || i == fa[x][0]) continue;
            top[i] = i; dfs2(i);
        }
        if (top[x] == x) {
            for (int i = 0, j = x; i <= mdep[x] - dep[x]; ++i, j = fa[j][0]) u[x].push_back(j);
            for (int i = 0, j = x; i <= mdep[x] - dep[x]; ++i, j = lson[j]) d[x].push_back(j);
        }
    }
    void init () { dfs1(1, 0); top[1] = 1, cnt = 0; dfs2(1); }
    int query (int x, int k) {
        if (!k) return x; if (k >= dep[x]) return 0;
        int t = lg2[k]; x = fa[x][t], k -= 1 << t;
        k -= dep[x] - dep[top[x]]; x = top[x];
        if (k >= 0) return u[x][k]; else return d[x][-k];
    }
} kth;
int top[MAXN];
void dfs2 (int x, int f) {
    if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
    for (auto i: E[x]) if (i != f && i != wson[x]) {
        top[i] = i; dfs2(i, x);
    }
}
int lca (int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]][0];
    }
    return dep[u] < dep[v] ? u : v;
}
int calc (int u, int v, int Lca, int len, int mod, int *pow, int *ipow, int *pre, int *suf) {
    // printf("calc(%d -> %d, lca = %d, len = %d, mod = %d)\n", u, v, Lca, len, mod);
    if (dep[u] - dep[Lca] + 1 >= len) {
        int qwq = kth.query(u, len);
        // printf("set1 %d\n", qwq);
        return (1ll * (suf[u] - suf[qwq]) % mod * ipow[dep[qwq]] % mod + mod) % mod;
    }
    else {
        int qwq = kth.query(v, dep[u] + dep[v] - 2 * dep[Lca] + 1 - len), awa = pow[dep[qwq] - dep[Lca]];
        // printf("set2 %d\n", qwq);
        int h1 = 1ll * (suf[u] - suf[fa[Lca][0]]) % mod * ipow[dep[Lca] - 1] % mod * awa % mod;
        int h2 = (pre[qwq] - 1ll * pre[Lca] * awa % mod) % mod;
        return ((h1 + h2) % mod + mod) % mod;
    }
}

int main () {
    n = read();
    int i, j;
    scanf("%s", val + 1);
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    for (i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    pow1[1] = pow2[1] = mul, ipow1[1] = qpow(mul, mod1 - 2, mod1), ipow2[1] = qpow(mul, mod2 - 2, mod2);
    for (i = 2; i <= n; i++)
        pow1[i] = 1ll * pow1[i - 1] * mul % mod1, pow2[i] = 1ll * pow2[i - 1] * mul % mod2,
        ipow1[i] = 1ll * ipow1[i - 1] * ipow1[1] % mod1, ipow2[i] = 1ll * ipow2[i - 1] * ipow2[1] % mod2;
    dfs1(1, 0); top[1] = 1; dfs2(1, 0);
    kth.init();
    q = read();
    while (q--) {
        int u = read(), v = read(), x = read(), y = read();
        int lca1 = lca(u, v), lca2 = lca(x, y);
        int L = 1, R = min(dep[u] + dep[v] - 2 * dep[lca1] + 1, dep[x] + dep[y] - 2 * dep[lca2] + 1), ans = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            // int bibo = calc(u, v, lca1, mid, mod1, pow1, ipow1, pre1, suf1);
            // int babo = calc(x, y, lca2, mid, mod1, pow1, ipow1, pre1, suf1);
            // printf("bibo = %d, babo = %d\n", bibo, babo);
            int burbo = calc(u, v, lca1, mid, mod2, pow2, ipow2, pre2, suf2);
            int barbo = calc(x, y, lca2, mid, mod2, pow2, ipow2, pre2, suf2);
            if (burbo == barbo) ans = mid, L = mid + 1;
            else R = mid - 1;
            // puts("===========");
        }
        printf("%d\n", ans);
    }
    return 0;
}