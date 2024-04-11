#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

vector<array<int, 2>> circuit;
multiset<int> adj[N];

void dfs(int u) {
    while (!adj[u].empty()) {
        int c = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        adj[c].erase(adj[c].find(u));
        dfs(c);
        circuit.push_back({c, u});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> odd;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() % 2 == 1) {
            odd.push_back(i);
        }
    }

    while (!odd.empty()) {
        int u = odd.back();
        odd.pop_back();
        int v = odd.back();
        odd.pop_back();

        adj[u].insert(v);
        adj[v].insert(u);
        ++m;
    }

    if (m % 2 == 1) {
        adj[1].insert(1);
        adj[1].insert(1);
        ++m;
    }

    dfs(1);

    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        auto [u, v] = circuit[i];
        if (i % 2 == 1) {
            swap(u, v);
        }
        cout << u << " " << v << "\n";
    }
}