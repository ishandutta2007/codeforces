#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
    visited[u] = true;
    int result = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            result += dfs(v);
        }
    }
    return result;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> edges(n);
    for (auto &[u, v] : edges) cin >> u, --u;
    for (auto &[u, v] : edges) cin >> v, --v;

    adj.assign(n, vector<int>());
    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int odds = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            odds += dfs(i) % 2;

    long long answer = 0;
    for (int i = 0; 2 * i < n - odds; ++i) {
        answer += 2 * (n - 1 - 2 * i);
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}