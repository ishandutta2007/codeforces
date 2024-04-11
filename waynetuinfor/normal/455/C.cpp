#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> G[maxn], nd[maxn];
int id[maxn], t, dis, fur, dia[maxn];
bool v[maxn];

void dfs(int now, int d, bool f = true) {
    if (d > dis) dis = d, fur = now;
    v[now] = true;
    if (f) {
        id[now] = t;
        nd[t].push_back(now);
    }
    for (int u : G[now]) {
        if (!v[u]) dfs(u, d + 1, f);
    }
}

inline int c(int k) {
    return k / 2 + (k & 1);
}

struct DisjointSet {
    vector<int> p, sz, d;
    void init(int n) {
        p.resize(n); sz.resize(n); d.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i; sz[i] = 1; d[i] = dia[i];
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x]; p[x] = y;
        d[y] = max({ d[x], d[y], c(d[x]) + c(d[y]) + 1 });
    }
    int get(int x) {
        return d[find(x)];
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!id[i]) {
        dis = 0; fur = 0; ++t;
        dfs(i, 0);
        for (int u : nd[t]) v[u] = false;
        dis = 0; dfs(fur, 0, false);
        for (int u : nd[t]) v[u] = false;
        dia[t] = dis;
    }
    dsu.init(t + 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            cout << dsu.get(id[x]) << endl;
        } else {
            int x, y; cin >> x >> y;
            dsu.merge(id[x], id[y]);
        }
    }
    return 0;
}