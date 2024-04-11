#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    pair<int, int> max_node;
    int lazy = 0;

    segtree(int l, int r) {
        if (l == r) {
            max_node = {0, l};
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r);
            pull();
        }
    }

    void apply(int x) {
        max_node.first = max(0, max_node.first + x);
        lazy += x;
    }

    void pull() {
        max_node = max(left->max_node, right->max_node);
    }

    void push() {
        if (lazy != 0) {
            left->apply(lazy);
            right->apply(lazy);
            lazy = 0;
        }
    }

    void update(int a, int b, int x, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            apply(x);
        } else {
            push();
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
            pull();
        }
    }
};

vector<int> adj[N];
int n, k;

long long get_score(int r, int b) {
    b = min(n / 2, b);
    return (long long) r * (n - r) - (long long) b * (n - b);
}

int in[N], out[N], where[N], par[N], depth, timer;
segtree *max_ancestors;

void dfs(int u) {
    ++depth;
    in[u] = ++timer;
    where[in[u]] = u;

    for (auto c : adj[u]) {
        adj[c].erase(ranges::find(adj[c], u));
        par[c] = u;
        dfs(c);
    }

    if (adj[u].empty()) {
        max_ancestors->update(in[u], in[u], depth, 1, n);
    }
    
    out[u] = timer;
    --depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    max_ancestors = new segtree(1, n);

    dfs(1);

    int r = 0, b = n;
    while (k > 0) {
        auto [d, u] = max_ancestors->max_node;

        if (get_score(r + 1, b - d) <= get_score(r, b)) break;

        --k, ++r, b -= d;

        u = where[u];
        while (d--) {
            max_ancestors->update(in[u], out[u], -1, 1, n);
            u = par[u];
        }
    }

    cout << get_score(r, b) << "\n";
}