#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(vector<int>& dist, int src) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto c : adj[v]) {
            if (dist[c] == 1e9) {
                q.push(c);
                dist[c] = dist[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (auto& i : a) {
        cin >> i;
    }
    adj.resize(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> from1(n + 1, 1e9), fromN(n + 1, 1e9);
    bfs(from1, 1);
    bfs(fromN, n);
    vector<pair<int, int>> data(k);
    for (int i = 0; i < k; ++i) {
        data[i] = {from1[a[i]] - fromN[a[i]], a[i]};
    }
    sort(data.begin(), data.end());

    int sol = 0, mx = -1e9;
    for (auto i : data) {
        sol = max(sol, mx + fromN[i.second]);
        mx = max(mx, from1[i.second]);
    }
    cout << min(sol + 1, from1[n]) << '\n';
}