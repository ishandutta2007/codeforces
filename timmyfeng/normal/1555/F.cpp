#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n) : n(n) {
        tree.resize(n + 1);
    }

    void update(int a, T x) {
        for ( ; a <= n; a += (a & -a)) {
            tree[a] += x;
        }
    }

    T query(int a) {
        T res = 0;
        for ( ; a > 0; a -= (a & -a)) {
            res += tree[a];
        }
        return res;
    }

    int lower_bound(T k) {
        int res = 0;
        T sum = 0;
        for (int i = __lg(n); i >= 0; --i) {
            if (res + (1 << i) <= n && sum + tree[res + (1 << i)] < k) {
                res += 1 << i;
                sum += tree[res];
            }
        }
        return res + 1;
    }
};

struct union_find {
    vector<int> par, size;

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

const int N = 300000, Q = 500000, L = __lg(N) + 1;

int xor_sum[N], par[L][N], in[N], out[N], n, q, t;
vector<array<int, 2>> adj[N];
array<int, 3> edges[Q];
bool ans[Q];

void dfs(int u) {
    in[u] = ++t;
    for (auto [c, w] : adj[u]) {
        if (c != par[0][u]) {
            xor_sum[c] = xor_sum[u] ^ w;
            par[0][c] = u;
            dfs(c);
        }
    }
    out[u] = t + 1;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    union_find dsu(n);
    for (int i = 0; i < q; ++i) {
        int u, v, w;
        cin >> u >> v >> w; --u, --v;

        edges[i] = {u, v, w};
        if (dsu.unite(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            ans[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            par[0][i] = i;
            dfs(i);
        }
    }

    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 0; j < n; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    fenwick<int> fenw(n);
    for (int i = 0; i < q; ++i) {
        auto [u, v, w] = edges[i];
        if ((xor_sum[u] ^ xor_sum[v] ^ w) == 1) {
            int p = lca(u, v);
            if (fenw.query(in[u]) + fenw.query(in[v]) - 2 * fenw.query(in[p]) == 0) {
                ans[i] = true;
                for (int c = u; c != p; c = par[0][c]) {
                    fenw.update(in[c], 1);
                    fenw.update(out[c], -1);
                }
                for (int c = v; c != p; c = par[0][c]) {
                    fenw.update(in[c], 1);
                    fenw.update(out[c], -1);
                }
            }
        }

        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}