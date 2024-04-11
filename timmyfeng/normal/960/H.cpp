#include <bits/stdc++.h>
using namespace std;

struct segtree {

    segtree *left = nullptr, *right = nullptr;
    int lazy = 0, sum1 = 0;
    long long sum2 = 0;

    void apply(int x, int l, int r) {
        sum2 += (long long) x * (2 * sum1 + (r - l + 1) * x);
        sum1 += (r - l + 1) * x;
        lazy += x;
    }

    void pull() {
        sum1 = left->sum1 + right->sum1;
        sum2 = left->sum2 + right->sum2;
    }

    void push(int l, int r) {
        if (left == nullptr) {
            left = new segtree();
            right = new segtree();
        }

        if (lazy != 0) {
            int m = (l + r) / 2;
            left->apply(lazy, l, m);
            right->apply(lazy, m + 1, r);
            lazy = 0;
        }
    }

    void update(int a, int b, int x, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            apply(x, l, r);
        } else {
            push(l, r);
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
            pull();
        }
    }

};

const int N = 50000 + 1;

int par[N], sub[N], in[N], root[N], t;
vector<int> adj[N];

void dfs_sub(int u) {
    sub[u] = 1;
    for (auto &c : adj[u]) {
        dfs_sub(c);
        sub[u] += sub[c];
        if (sub[c] > sub[adj[u][0]]) {
            swap(c, adj[u][0]);
        }
    }
}

void dfs_hld(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        root[c] = c == adj[u][0] ? root[u] : c;
        dfs_hld(c);
    }
}

int flavor[N], cost[N], n;
segtree *sum[N];

void update(int u, int x) {
    int k = flavor[u];
    while (u > 0) {
        sum[k]->update(in[root[u]], in[u], x, 1, n);
        u = par[root[u]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(8);

    int m, q, c;
    cin >> n >> m >> q >> c;

    for (int i = 1; i <= n; ++i) {
        cin >> flavor[i];
    }

    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    for (int i = 1; i <= m; ++i) {
        cin >> cost[i];
    }

    root[1] = 1;
    dfs_sub(1);
    dfs_hld(1);

    for (int i = 1; i <= m; ++i) {
        sum[i] = new segtree();
    }

    for (int i = 1; i <= n; ++i) {
        update(i, 1);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, w;
            cin >> x >> w;
            update(x, -1);
            flavor[x] = w;
            update(x, 1);
        } else {
            int k;
            cin >> k;

            cout << 
                (double) cost[k] * cost[k] * sum[k]->sum2 / n -
                (double) 2 * c * cost[k] * sum[k]->sum1 / n +
                (double) c * c << "\n";
        }
    }
}