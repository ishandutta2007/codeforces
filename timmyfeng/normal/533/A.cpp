#include <bits/stdc++.h>
using namespace std;

const int N = 500001;

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    int mini = 0, lazy = 0;

    void apply(int x) {
        mini += x, lazy += x;
    }

    void push() {
        if (!left) {
            left = new segtree();
            right = new segtree();
        }

        if (lazy != 0) {
            left->apply(lazy);
            right->apply(lazy);
            lazy = 0;
        }
    }

    void update(int a, int x, int l, int r) {
        if (a < l) {
            return;
        } else if (a >= r) {
            apply(x);
        } else {
            push();
            int m = (l + r) / 2;
            left->update(a, x, l, m);
            right->update(a, x, m + 1, r);
            mini = min(left->mini, right->mini);
        }
    }
};

int par[N], cave[N], miner[N];
vector<int> adj[N];

int root[N], path[N], alt[N], ans;
vector<int> subtree[N];

void dfs_min(int u, int *h) {
    for (auto c : adj[u]) {
        if (c != par[u]) {
            h[c] = min(h[u], cave[c]);
            par[c] = u;
            dfs_min(c, h);
        }
    }
}

void dfs_nodes(int u, vector<int> &v) {
    v.push_back(u);
    for (auto c : adj[u]) {
        if (c != par[u]) {
            dfs_nodes(c, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> cave[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    path[1] = cave[1];
    dfs_min(1, path);

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> miner[i];
    }

    sort(miner, miner + n, greater<int>());

    priority_queue<array<int, 2>> queue;
    queue.push({path[1], 1});

    for (k = 0; k < n; ++k) {
        auto [h, u] = queue.top();
        if (miner[k] > h) {
            break;
        }

        queue.pop();
        for (auto c : adj[u]) {
            if (c != par[u]) {
                queue.push({path[c], c});
            }
        }
    }

    if (queue.empty()) {
        cout << 0 << "\n";
        exit(0);
    }

    set<int> values(miner + k, miner + n);
    int m = 0;

    for ( ; !queue.empty(); ++m) {
        root[m] = queue.top()[1];
        queue.pop();

        alt[root[m]] = miner[k];
        dfs_min(root[m], alt);
        dfs_nodes(root[m], subtree[m]);

        for (auto i : subtree[m]) {
            values.insert(path[i]);
            values.insert(alt[i]);
        }
    }

    map<int, int> id;
    for (auto i : values) {
        int j = id.size();
        id[i] = j;
    }
    int s = id.size();

    segtree *capacity = new segtree();
    int ans = INT_MAX;

    for (int i = k; i < n; ++i) {
        capacity->update(id[miner[i]], -1, 1, s);
    }

    for (int i = 0; i < m; ++i) {
        for (auto j : subtree[i]) {
            capacity->update(id[path[j]], 1, 1, s);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (auto j : subtree[i]) {
            capacity->update(id[path[j]], -1, 1, s);
            capacity->update(id[alt[j]], 1, 1, s);
        }

        if (capacity->mini == 0) {
            ans = min(ans, miner[k] - cave[root[i]]);
        }

        for (auto j : subtree[i]) {
            capacity->update(id[path[j]], 1, 1, s);
            capacity->update(id[alt[j]], -1, 1, s);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}