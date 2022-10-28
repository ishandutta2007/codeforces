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
        if (a == 0) {
            return;
        }

        for ( ; a <= n; a += a & -a) {
            tree[a] += x;
        }
    }

    T query(int a) {
        T res = 0;
        for ( ; a > 0; a -= a & -a) {
            res += tree[a];
        }
        return res;
    }

};

const int N = 300000 + 1;
const int L = __lg(N) + 1;

int par[L][N], depth[N], in[N], out[N], t, n;
vector<array<int, 5>> layer[N];
vector<int> adj[N];

void dfs(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        if (c != par[0][u]) {
            depth[c] = depth[u] + 1;
            par[0][c] = u;
            dfs(c);
        }
    }
    out[u] = t;
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    for (int i = __lg(n); i >= 0; --i) {
        if (!ancestor(par[i][u], v)) {
            u = par[i][u];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    out[0] = t;

    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 1; j <= n; ++j) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    int m;
    cin >> m;

    map<array<int, 3>, int> count;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        int a = lca(v, u), b = lca(u, v), p = par[0][a];
        if (a > b) {
            swap(a, b);
        }

        if (ancestor(u, v)) {
            p = u;
        } else if (ancestor(v, u)) {
            p = v;
        }

        layer[depth[p]].push_back({u, v, p, a, b});
        if (a != p && b != p) {
            ++count[{p, a, b}];
        }
    }

    long long ans = 0;
    fenwick<int> fenw(n);
    for (int i = 0; i < n; ++i) {
        for (auto &[u, v, p, a, b] : layer[i]) {
            ans += fenw.query(out[p]) - fenw.query(in[p] - 1);
            for (auto c : {a, b}) {
                if (c != p) {
                    ans -= fenw.query(out[c]) - fenw.query(in[c] - 1);
                }
            }
            fenw.update(in[u], 1);
            fenw.update(in[v], 1);
            fenw.update(in[p], -1);
            fenw.update(in[par[0][p]], -1);
        }
    }

    for (auto &i : count) {
        ans += (long long) i.second * (i.second - 1) / 2;
    }

    cout << ans << "\n";
}