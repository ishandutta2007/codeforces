#include <bits/stdc++.h>
using namespace std;

struct union_find {

    vector<int> par;

    union_find() {}

    union_find(int n) {
        par.resize(n);
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
            par[v] = u;
            return true;
        }
        return false;
    }

};

const int N = 100000 + 1;
const int B = 1024;

int in[N], out[N], par[N], depth[N], t;
vector<int> adj[N];

void dfs_time(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        depth[c] = depth[u] + 1;
        dfs_time(c);
    }
    out[u] = t;
}

void normalize(vector<int> &v) {
    sort(v.begin(), v.end(), [&](int a, int b) {
        return in[a] < in[b];
    });
    v.erase(unique(v.begin(), v.end()), v.end());
}

vector<array<int, 2>> pairs[N];
vector<int> nodes[B];
union_find dsu;

void dfs_lca(int u) {
    for (auto [v, i] : pairs[u]) {
        nodes[i].push_back(dsu.find(v));
    }

    for (auto c : adj[u]) {
        dfs_lca(c);
        dsu.unite(u, c);
    }
}

bool color[N], in_vir[N], cleared[N];
vector<array<int, 2>> vir[N];
int pushed[N];

void dfs_update(int u, int push, bool clear) {
    if (in_vir[u]) {
        push = pushed[u];
        clear = cleared[u];
    } else {
        if (clear) {
            color[u] = false;
        }

        if (!color[u] && push > 0) {
            color[u] = true;
            --push;
        }
    }

    for (auto c : adj[u]) {
        dfs_update(c, push, clear);
    }
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

void dfs_black(int u) {
    if (!color[u]) {
        color[u] = true;
        return;
    }

    ++pushed[u];
    for (auto &[c, w] : vir[u]) {
        if (w == 0) {
            dfs_black(c);
        } else {
            --w;
        }
    }
}

void dfs_white(int u) {
    cleared[u] = true;
    color[u] = false;
    pushed[u] = 0;

    for (auto &[c, w] : vir[u]) {
        w = depth[c] - depth[u] - 1;
        dfs_white(c);
    }
}

array<int, 2> queries[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    dfs_time(1);

    for (int i = 0; i < q; ++i) {
        int t, u;
        cin >> t >> u;
        queries[i] = {t, u};
        nodes[i / B].push_back(u);
    }

    for (int i = 0; i <= (q - 1) / B; ++i) {
        normalize(nodes[i]);
        for (int j = 1; j < (int) nodes[i].size(); ++j) {
            pairs[nodes[i][j]].push_back({nodes[i][j - 1], i});
        }
    }

    dsu = union_find(n + 1);
    dfs_lca(1);

    for (int i = 0; i <= (q - 1) / B; ++i) {
        normalize(nodes[i]);
    }

    for (int i = 0; i < q; ++i) {
        if (i % B == 0) {
            dfs_update(1, 0, false);

            for (int j = 1; j <= n; ++j) {
                vir[j].clear();
                pushed[j] = 0;
                cleared[j] = in_vir[j] = false;
            }

            vector<int> stk = {nodes[i / B][0]};
            for (int j = 1; j < (int) nodes[i / B].size(); ++j) {
                int u = nodes[i / B][j];
                while (!ancestor(stk.back(), u)) {
                    stk.pop_back();
                }

                int v = stk.back(), w = 0;
                for (int k = par[u]; k != v; k = par[k]) {
                    w += !color[k];
                }

                vir[v].push_back({u, w});
                stk.push_back(u);
            }

            for (auto j : nodes[i / B]) {
                in_vir[j] = true;
            }
        }

        auto [t, u] = queries[i];
        if (t == 1) {
            dfs_black(u);
        } else if (t == 2) {
            dfs_white(u);
        } else {
            cout << (color[u] ? "black" : "white") << "\n";
        }
    }
}