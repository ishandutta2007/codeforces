#include <bits/stdc++.h>
using namespace std;

const int N = 300001;

vector<array<int, 2>> adj[N];
vector<int> nodes[N];
long long a[N];
int root[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    if (accumulate(a, a + n + 1, 0LL) < (long long) (n - 1) * x) {
        cout << "NO\n";
        exit(0);
    }

    cout << "YES\n";

    set<pair<long long, int>> maxi;
    for (int i = 1; i <= n; ++i) {
        maxi.insert({a[i], i});
        nodes[i].push_back(i);
        root[i] = i;
    }

    while (maxi.size() > 1) {
        int u = (--maxi.end())->second;
        maxi.erase(--maxi.end());

        while (root[adj[u].back()[0]] == u) {
            adj[u].pop_back();
        }

        auto [v, e] = adj[u].back();
        adj[u].pop_back();
        v = root[v];

        maxi.erase({a[v], v});

        cout << e << "\n";

        if (adj[u].size() + nodes[u].size() < adj[v].size() + nodes[v].size()) {
            swap(u, v);
        }

        a[u] += a[v] - x;

        for (auto c : nodes[v]) {
            root[c] = u;
        }

        adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
        nodes[u].insert(nodes[u].end(), nodes[v].begin(), nodes[v].end());

        maxi.insert({a[u], u});
    }
}