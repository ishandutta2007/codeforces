#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

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


#define ll long long
const int MAXN = 500050;

inline void out (ll x) { if (x >= 10) out(x / 10); putchar(x % 10 + '0'); }

int n, root;
int fa[MAXN], siz[MAXN], wson[MAXN], top[MAXN], dep[MAXN], dfn[MAXN], idfn[MAXN], cnt;
vector <int> E[MAXN], db[MAXN];

void dfs1 (int x, int f) {
    fa[x] = f, siz[x] = 1, dep[x] = dep[f] + 1;
    for (auto i: E[x]) dfs1(i, x), siz[x] += siz[i], wson[x] = siz[wson[x]] < siz[i] ? i : wson[x];
}
void dfs2 (int x, int f) {
    dfn[x] = ++cnt; idfn[cnt] = x;
    if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
    for (auto i: E[x]) if (i != wson[x]) top[i] = i, dfs2(i, x);
}

ll g[MAXN];

namespace BIT {
	ll l1[MAXN], l2[MAXN];
	int lowbit (int x) { return x & -x; }
	void add (ll *f, int x, ll k) { while (x <= n + 1) f[x] += k, x += lowbit(x); }
	ll ask (ll *f, int x) { ll ret = 0; while (x) ret += f[x], x -= lowbit(x); return ret; }
	ll rq (int x) { return (x + 1) * ask(l1, x) - ask(l2, x); }
	void ra (int x, ll k) { add(l1, x, k), add(l2, x, k * x); }
	ll query (int l, int r) { return rq(r) - rq(l - 1); }
	void modify (int l, int r, ll k) { ra(l, k), ra(r + 1, -k); }
}

void pathadd (int u, ll k) { while (u) BIT::modify(dfn[top[u]], dfn[u], k), u = fa[top[u]]; }
ll pathquery (int u) { ll ret = 0; while (u) ret += BIT::query(dfn[top[u]], dfn[u]), u = fa[top[u]]; return ret; }

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        j = read();
        if (j) E[j].push_back(i); else root = i;
    }
    dfs1(root, 0); top[root] = root; dfs2(root, 0);
    for (i = 1; i <= n; i++) db[dep[i]].push_back(i);
    for (i = 1; i <= n; i++) {
        for (auto j: db[i]) pathadd(j, 1);
        for (auto j: db[i]) g[j] = pathquery(j);
    }
    for (i = 1; i <= n; i++) out(g[i] - dep[i]), putchar(' ');
    flush();
    return 0;
}