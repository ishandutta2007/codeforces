#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

struct union_find {
    vector<int> par, size;

    union_find() {}

    union_find(int n) {
        par.resize(n);
        size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            par[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }
};

set<int> unvisited, adj[N];
array<int, 3> edges[N];
union_find dsu;
long long k;

void dfs(int u) {
    unvisited.erase(u);
    int c = -1;
    while (true) {
        auto it = unvisited.upper_bound(c);
        if (it == unvisited.end()) {
            return;
        }

        c = *it;
        if (adj[u].count(c) == 0) {
            dsu.unite(u, c);
            dfs(c);
            --k;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    k = (long long) n * (n - 1) / 2 - m;
    int sum = 0;

    for (int i = 0; i < m; ++i) {
        auto &[w, u, v] = edges[i];
        cin >> u >> v >> w;
        sum ^= w;
        --u, --v;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    dsu = union_find(n);
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        if (unvisited.count(i) > 0) {
            dfs(i);
        }
    }

    union_find positive(n);

    long long ans = 0;
    sort(edges, edges + m);
    for (int i = 0; i < m; ++i) {
        auto [w, u, v] = edges[i];
        if (!dsu.same(u, v)) {
            positive.unite(u, v);
            dsu.unite(u, v);
            ans += w;
        } else if (!positive.same(u, v)) {
            sum = min(sum, w);
        }
    }

    cout << ans + (k > 0 ? 0 : sum) << "\n";
}