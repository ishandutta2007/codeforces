#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 210000, F = 20;

struct edge {
    int u, v, w, id;
    void read (int t) { scanf ("%d%d%d", &u, &v, &w); id = t; }
} e[N];

bool cmp (edge a, edge b) {
    return a.w < b.w;
}

int fa[N], f[N][F], vis[N], d[N], mx[N][F];
LL ans[N];
vector <int> g[N], h[N];

int myfind (int x) {
    if (fa[x] == -1) return x;
    return fa[x] = myfind (fa[x]);
}

void dfs (int u, int fa, int dep, int dis) {
//    cout << u << ' ' << fa << ' ' << dep << ' ' << dis << endl;
    d[u] = dep;
    f[u][0] = fa;
    mx[u][0] = dis;
    for (int i = 1; i < F; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
        mx[u][i] = max (mx[u][i - 1], mx[f[u][i - 1]][i - 1]);
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u, dep + 1, h[u][i]);
    }
}

int getmax (int u, int v) {
    if (d[u] < d[v]) swap (u, v);
    int h = d[u] - d[v];
    int res = 0;
    for (int i = 0; i < F; i++) if (h & (1 << i)) {
        res = max (res, mx[u][i]);
        u = f[u][i];
    }
    if (u == v) return res;
    for (int i = F - 1; i >= 0; i--) if (f[u][i] != f[v][i]) {
        res = max (res, mx[u][i]);
        res = max (res, mx[v][i]);
        u = f[u][i];
        v = f[v][i];
    }
    res = max (res, mx[u][0]);
    res = max (res, mx[v][0]);
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        e[i].read(i);
    }
    sort (e + 1, e + 1 + m, cmp);
    memset (fa, -1, sizeof fa);
    LL res = 0;
    for (int i = 1; i <= m; i++) {
        int u = myfind (e[i].u);
        int v = myfind (e[i].v);
        if (u == v) continue;
        fa[u] = v;
        res += e[i].w;
        vis[i] = 1;
//        cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
        g[e[i].u].push_back (e[i].v);
        h[e[i].u].push_back (e[i].w);
        g[e[i].v].push_back (e[i].u);
        h[e[i].v].push_back (e[i].w);
    }
//    cout << res << endl;
    dfs (1, 0, 0, 0);
    for (int i = 1; i <= m; i++) {
        if (vis[i]) ans[e[i].id] = res;
        else {
//            cout << e[i].u <<' ' << e[i].v << ' ' << getmax (e[i].u, e[i].v) << endl;
            ans[e[i].id] = res - getmax (e[i].u, e[i].v) + e[i].w;
        }
    }
    for (int i = 1; i <= m; i++) printf("%I64d\n", ans[i]);
}