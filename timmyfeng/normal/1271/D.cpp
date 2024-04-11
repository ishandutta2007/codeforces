#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<int> portal(n + 1);
    iota(portal.begin(), portal.end(), 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        portal[v] = max(portal[v], u);
    }
    vector<vector<int>> adj(n + 1);
    for (int v = 1; v <= n; ++v) {
        adj[portal[v]].push_back(v);
    }

    int sol = 0;
    priority_queue<int> defended;
    for (int i = 1; i <= n; ++i) {
        while (!defended.empty() && k < a[i]) {
            sol += defended.top();
            defended.pop();
            ++k;
        }
        if (k < a[i]) {
            cout << -1 << '\n';
            exit(0);
        }
        k += b[i];
        for (auto j : adj[i]) {
            defended.push(-c[j]);
            sol += c[j];
            --k;
        }
    }
    while (k < 0) {
        sol += defended.top();
        defended.pop();
        ++k;
    }
    cout << sol << '\n';
}