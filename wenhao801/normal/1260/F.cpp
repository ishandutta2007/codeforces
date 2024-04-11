#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lint long long

namespace fast_IO {
    const int IN_LEN = 50000000, OUT_LEN = 50000000;
    char ibuf[IN_LEN], obuf[OUT_LEN], *ih = ibuf + IN_LEN, *oh = obuf;
    char *lastin = ibuf + IN_LEN;
    const char *lastout = ibuf + OUT_LEN - 1;
    inline char getchar_() {
        if (ih == lastin)lastin = ibuf + fread(ibuf, 1, IN_LEN, stdin), ih = ibuf;
        return (*ih++);
    }
    inline void putchar_(const char x) {
        if (ih == lastout)fwrite(obuf, 1, oh - obuf, stdout), oh = obuf;
        *oh++ = x;
    }
    inline void flush() { fwrite(obuf, 1, oh - obuf, stdout); }
}
using namespace fast_IO;
#define getchar() getchar_()
#define putchar(x) putchar_((x))

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200100;
const lint mod = 1e9 + 7;

struct A { int l, r, id; } a[MAXN], b[MAXN], c[MAXN];
int n;

lint qpow (lint x, lint y) {
    lint ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

lint inv (lint x) { return qpow(x, mod - 2); }

bool cmp1 (A x, A y) { return x.l < y.l; }
bool cmp2 (A x, A y) { return x.r < y.r; }
    
struct Edge {
    int nex;
    int to;
} edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

int fa[MAXN], siz[MAXN], dep[MAXN], wson[MAXN];

void dfs1 (int x, int f) {
    fa[x] = f;
    dep[x] = dep[f] + 1;
    int i, j;
    siz[x] = 1;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j == f) continue;
        dfs1(j, x);
        siz[x] += siz[j];
        if (siz[wson[x]] < siz[j]) wson[x] = j;
    }
    return;
}

int top[MAXN], dfn[MAXN];

void dfs2 (int x) {
    dfn[x] = ++cnt;
    if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x]);
    int i, j;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j == fa[x] || j == wson[x]) continue;
        top[j] = j;
        dfs2(j);
    }
    return;
}

int w[MAXN] = {};
lint lastans = 0;

lint X = 0, Y = 0;

lint tree[MAXN << 2], lazy[MAXN << 2];
void pushup (int root) { tree[root] = (tree[root << 1] + tree[root << 1 | 1]) % mod; }
void cover (int o, lint siz, lint k) { tree[o]=(tree[o]+k*siz)%mod; lazy[o]=(lazy[o]+k)%mod;}
void pushdown (int l, int r, int root) {
    int mid = (l + r) >> 1;
    cover(root << 1, mid - l + 1, lazy[root]), cover(root << 1 | 1, r - mid, lazy[root]), lazy[root] = 0;
}
void modify (int l, int r, lint k, int L, int R, int root) {
    if (l <= L && R <= r) {
        cover(root, R - L + 1, k);
        return;
    }
    pushdown(L, R, root);
    int mid = (L + R) >> 1;
    if (mid >= l) modify(l, r, k, L, mid, root << 1);
    if (mid < r) modify(l, r, k, mid + 1, R, root << 1 | 1);
    pushup(root);   
}

lint query (int l, int r, int L, int R, int root) {
    if (l <= L && R <= r) return tree[root];
    pushdown(L, R, root);
    int mid = (L + R) >> 1;
    lint ret = 0;
    if (mid >= l) ret = (ret + query(l, r, L, mid, root << 1)) % mod;
    if (mid < r) ret = (ret + query(l, r, mid + 1, R, root << 1 | 1)) % mod;
    return (ret % mod + mod) % mod;
}

lint line_query (int x) {
    lint ret = 0;
    while (x) {
        //printf("%lld %lld %lld %lld\n", top[x], x, dfn[top[x]], dfn[x]);
        ret = (ret + query(dfn[top[x]], dfn[x], 1, n, 1)) % mod;
        x = fa[top[x]];
    }
    //printf("qry(%lld) = %lld\n", t, ret);
    return ret;
}

void line_modify (int x, lint k) {
    //printf("mod(%lld %lld)\n", x, (mod + k * w[x]) % mod);
    while (x) {
        modify(dfn[top[x]], dfn[x], k, 1, n, 1);
        x = fa[top[x]];
    }
}

void MOD (int x, lint k, lint K) {
    //printf("!!! %lld %lld !!! \n", k * w[x] * ((X + Y * dep[x] - 2 * (line_query(x) - line_query(1))) % mod + mod) % mod, X + Y * dep[x]);
    lastans = (lastans + k * ((X + Y * dep[x] - 2 * (((line_query(x) - line_query(1)) % mod + mod) % mod)) % mod + mod) % mod) % mod;
    //printf("LQ(%lld) = %lld; %lld; %lld\n", x, line_query(x) - line_query(1), w[x], lastans);
    line_modify(x, k);
    X = (X + k * dep[x]) % mod;
    Y = (Y + k) % mod;
    //cout << lastans << ' ' << X << ' ' << Y << ' ' << ((line_query(x) - line_query(1)) % mod + mod) % mod << endl << endl;
}

signed main () {
    n = read();
    int i, j;
    int Maxcol = 0;
    for (i = 1; i <= n; i++) {
        a[i].l = read(), a[i].r = read();
        b[i].l = c[i].l = a[i].l, b[i].r = c[i].r = a[i].r;
        a[i].id = b[i].id = c[i].id = i;
        Maxcol = max(Maxcol, a[i].r);
    }
    sort(b + 1, b + n + 1, cmp1);
    sort(c + 1, c + n + 1, cmp2);
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    dep[0] = -1;
    dfs1(1, 0);
    cnt = 0;
    top[1] = 1;
    dfs2(1);
    for (i = 1; i <= n; i++) w[i] = inv(a[i].r - a[i].l + 1);
    lint ans = 0;
    lint t = 1;
    for (i = 1; i <= n; i++) t = t * (lint)(a[i].r - a[i].l + 1) % mod;
    int L = 1, R = 1;
    for (i = 1; i <= Maxcol; i++) {
        while (b[L].l == i && L <= n) { MOD(b[L].id, w[b[L].id], 1); L++; }
        while (c[R].r < i && R <= n) { MOD(c[R].id, mod - w[c[R].id], -1); R++; }
        //printf("\n! %lld\n", lastans);
        ans = (ans + lastans) % mod;
    }
    printf("%lld\n", ans * t % mod);
    flush();
    return 0;
}