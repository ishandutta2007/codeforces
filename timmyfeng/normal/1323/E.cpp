#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<long long> c;
    vector<vector<int>> adj;
    map<vector<int>, long long> sum;
    while (t--) {
        int n, m;
        cin >> n >> m;
        c.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        adj.assign(n + 1, vector<int>());
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
        }

        sum.clear();
        for (int i = 1; i <= n; ++i) {
            if (adj[i].empty()) continue;
            sort(adj[i].begin(), adj[i].end());
            sum[adj[i]] += c[i];
        }

        long long sol = 0;
        for (auto& i : sum) {
            sol = __gcd(sol, i.second);
        }
        cout << sol << '\n';
    }
}