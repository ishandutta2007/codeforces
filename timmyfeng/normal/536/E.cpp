#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int L = __lg(N) + 1;

array<int, 4> queries[N];
array<int, 3> edges[N];
int ans[N], f[N], n;

struct path {
    int prefix = 0, suffix = 0, length = 0, t = 0;

    friend path operator+(const path &l, const path &r) {
        return {
            l.prefix < l.length ? l.prefix : l.length + r.prefix,
            r.suffix < r.length ? r.suffix : l.suffix + r.length,
            l.length + r.length,
            l.t + r.t - f[l.suffix] - f[r.prefix] + f[l.suffix + r.prefix]
        };
    }
};

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    path value;

    segtree(int l, int r) {
        if (l == r) {
            value.length = 1;
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r);
            value = left->value + right->value;
        }
    }

    void update(int a, int l, int r) {
        if (l == r) {
            value = {1, 1, 1, f[1]};
        } else {
            int m = (l + r) / 2;
            if (a <= m) {
                left->update(a, l, m);
            } else {
                right->update(a, m + 1, r);
            }
            value = left->value + right->value;
        }
    }

    path query(int a, int b, int l, int r) {
        if (b < l || r < a) {
            return path();
        } else if (a <= l && r <= b) {
            return value;
        } else {
            int m = (l + r) / 2;
            return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
        }
    }
};

int sub[N], in[N], out[N], root[N], par[L][N], t;
vector<int> adj[N];

void dfs_sub(int u) {
    sub[u] = 1;
    for (auto &c : adj[u]) {
        adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
        par[0][c] = u;
        dfs_sub(c);

        sub[u] += sub[c];
        if (sub[c] > sub[adj[u][0]]) {
            swap(adj[u][0], c);
        }
    }
}

void dfs_hld(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        root[c] = c == adj[u][0] ? root[u] : c;
        dfs_hld(c);
    }
    out[u] = t;
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }

    for (int i = __lg(n); i >= 0; --i) {
        if (!ancestor(par[i][u], v)) {
            u = par[i][u];
        }
    }
    return par[0][u];
}

path query(int u, int v, segtree *t_tree) {
    path ans;
    while (root[v] != root[u]) {
        ans = t_tree->query(in[root[v]], in[v], 1, n) + ans;
        v = par[0][root[v]];
    }

    if (u != v) {
        ans = t_tree->query(in[u] + 1, in[v], 1, n) + ans;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        cin >> f[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {w, u, v};
    }
    sort(edges, edges + n - 1);

    for (int i = 0; i < q; ++i) {
        auto &[w, u, v, id] = queries[i];
        cin >> u >> v >> w;
        id = i;
    }
    sort(queries, queries + q);

    root[1] = 1;
    dfs_sub(1);
    dfs_hld(1);
    out[0] = t;

    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 1; j <= n; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    segtree *t_tree = new segtree(1, n);
    for (int i = q - 1, j = n - 2; i >= 0; --i) {
        while (j >= 0 && edges[j][0] >= queries[i][0]) {
            auto [w, u, v] = edges[j--];
            t_tree->update(max(in[u], in[v]), 1, n);
        }

        auto [w, u, v, id] = queries[i];
        int p = lca(u, v);

        path l = query(p, u, t_tree);
        path r = query(p, v, t_tree);
        swap(l.prefix, l.suffix);

        ans[id] = (l + r).t;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}