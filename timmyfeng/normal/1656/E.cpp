#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj[N];
int a[N];

void dfs(int u, int p, int k) {
    a[u] *= k;
    for (auto c : adj[u]) {
        if (c != p) dfs(c, u, -k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        fill(adj, adj + n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; ++i) {
            a[i] = adj[i].size();
        }

        dfs(0, -1, 1);

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}