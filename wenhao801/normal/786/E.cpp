#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1200020, inf = 1e9 + 7;
vector <int> E[MAXN]; int n, m, ide[MAXN], idq[MAXN];

int fa[MAXN], siz[MAXN], wson[MAXN], top[MAXN], dep[MAXN], dfn[MAXN], idfn[MAXN], cnt;
void dfs1 (int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1;
    for (auto v: E[x]) if (v != f) {
        dfs1(v, x); siz[x] += siz[v];
        if (siz[v] > siz[wson[x]]) wson[x] = v;
    }
}
void dfs2 (int x, int f) {
    dfn[x] = ++cnt; idfn[cnt] = x;
    if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
    for (auto v: E[x]) if (v != f && v != wson[x]) {
        top[v] = v; dfs2(v, x);
    }
}

namespace maxflow {
    struct Edge { int nex, to, w; } edge[MAXN]; int head[MAXN], cur[MAXN], elen = 1;
    int add (int u, int v, int w) {
        edge[++elen].to = v; edge[elen].nex = head[u];
        head[u] = elen; edge[elen].w = w;
        edge[++elen].to = u; edge[elen].nex = head[v];
        head[v] = elen; edge[elen].w = 0;
        return elen - 1;
    }

    int N, s, t;

    int dis[MAXN]; queue <int> q;
    bool bfs () {
        int i, j;
        for (i = 1; i <= N; i++) dis[i] = 0, cur[i] = head[i];
        dis[s] = 1; q.push(s);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (i = head[x]; i; i = edge[i].nex) if (!dis[edge[i].to] && edge[i].w) {
                dis[edge[i].to] = dis[x] + 1;
                q.push(edge[i].to);
            }
        }
        return dis[t];
    }
    int dfs (int x, int rem) {
        if (x == t || !rem) return rem;
        int i, j, ret = 0;
        for (i = cur[x]; i; i = edge[i].nex) {
            cur[x] = i; j = edge[i].to;
            if (dis[j] == dis[x] + 1 && edge[i].w) {
                int res = dfs(j, min(edge[i].w, rem));
                ret += res; rem -= res;
                edge[i].w -= res; edge[i ^ 1].w += res;
                if (!rem) return ret;
            }
        }
        return ret;
    }
    int dinic () { int ret = 0; while (bfs()) ret += dfs(s, inf); return ret; }
    bool vis[MAXN];
    void dfs (int x) {
        if (vis[x]) return;
        vis[x] = 1;
        for (int i = head[x]; i; i = edge[i].nex) if (edge[i].w) dfs(edge[i].to);
    }
}

namespace seg {
    int id[MAXN];
    void build (int l, int r, int x) {
        if (l == r) { id[x] = idfn[l]; return; }
        id[x] = ++maxflow::N;
        int mid = (l + r) >> 1;
        build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
        maxflow::add(id[x << 1], id[x], inf); maxflow::add(id[x << 1 | 1], id[x], inf);
    }
    void link (int l, int r, int now, int L, int R, int x) {
        if (l <= L && R <= r) { maxflow::add(id[x], now, inf); return; }
        int mid = (L + R) >> 1;
        if (l <= mid) link(l, r, now, L, mid, x << 1);
        if (mid < r) link(l, r, now, mid + 1, R, x << 1 | 1);
    }
}

void lca (int u, int v, int now) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        seg::link(dfn[top[u]], dfn[u], now, 2, n, 1);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (u != v) seg::link(dfn[u] + 1, dfn[v], now, 2, n, 1);
}

int id[MAXN]; pair <int, int> iee[MAXN];
vector <int> ans1, ans2;

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read(); iee[i] = make_pair(u, v);
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs1(1, 0); top[1] = 1; dfs2(1, 0);
    for (i = 1; i < n; i++) {
        int u = iee[i].first, v = iee[i].second;
        if (dep[u] > dep[v]) swap(u, v);
        id[v] = i;
    }
    maxflow::N = n + 1; maxflow::s = 1; maxflow::t = n + 1;
    for (i = 2; i <= n; i++) ide[i] = maxflow::add(maxflow::s, i, 1);
    seg::build(2, n, 1);
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), now = ++maxflow::N;
        lca(u, v, now);
        idq[i] = maxflow::add(now, maxflow::t, 1);
    }
    printf("%d\n", maxflow::dinic());
    maxflow::dfs(maxflow::s);
    for (i = 1; i <= m; i++) {
        int u = maxflow::edge[idq[i]].to, v = maxflow::edge[idq[i] ^ 1].to;
        if (maxflow::vis[u] ^ maxflow::vis[v]) ans1.push_back(i);
    }
    printf("%d ", ans1.size()); for (auto v: ans1) printf("%d ", v); puts("");
    for (i = 2; i <= n; i++) {
        int u = maxflow::edge[ide[i]].to, v = maxflow::edge[ide[i] ^ 1].to;
        // printf("e %d %d\n", u, v);
        if (maxflow::vis[u] ^ maxflow::vis[v]) ans2.push_back(id[i]);
    }
    sort(ans2.begin(), ans2.end()); printf("%d ", ans2.size());
    for (auto v: ans2) printf("%d ", v); puts("");
    return 0;
}