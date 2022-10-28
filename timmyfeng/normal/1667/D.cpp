#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<int> adj[N], order[N][2];
bool solved[N][2];

void dfs(int u, int p) {
    for (auto c : adj[u]) {
        if (c != p) dfs(c, u);
    }

    for (int parity : {0, 1}) {
        vector<pair<int, int>> neighbors;
        for (auto v : adj[u]) {
            if (v == p) neighbors.push_back({2 * parity, v});
            else if (solved[v][0] && solved[v][1]) neighbors.push_back({1, v});
            else if (solved[v][0]) neighbors.push_back({0, v});
            else if (solved[v][1]) neighbors.push_back({2, v});
            else solved[u][parity] = false;
        }
        sort(neighbors.begin(), neighbors.end());

        int l = 0, r = (int) neighbors.size() - 1;
        while (l <= r) {
            if ((r - l) % 2) {
                solved[u][parity] &= (neighbors[r].first >= 1);
                order[u][parity].push_back(neighbors[r--].second);
            } else {
                solved[u][parity] &= (neighbors[l].first <= 1);
                order[u][parity].push_back(neighbors[l++].second);
            }
        }
    }
}

void dfs_print(int u, int p, int parity) {
    int parity_v = 1 - adj[u].size() % 2;
    for (auto v : order[u][parity]) {
        if (v == p) cout << u << " " << p << "\n";
        else dfs_print(v, u, parity_v);
        parity_v = 1 - parity_v;
    }
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        for (int parity : {0, 1}) {
            solved[i][parity] = true;
            order[i][parity].clear();
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    if (solved[1][0]) {
        cout << "YES\n";
        dfs_print(1, 0, 0);
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}