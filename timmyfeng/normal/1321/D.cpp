#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> opt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (auto& i : p) {
        cin >> i;
    }

    queue<int> bfs;
    opt.resize(n + 1);
    vector<int> dist(n + 1, 1e9);
    bfs.push(p.back());
    dist[p.back()] = 0;
    while (!bfs.empty()) {
        int c = bfs.front();
        bfs.pop();
        for (auto i : adj[c]) {
            if (dist[c] + 1 <= dist[i]) {
                opt[i].push_back(c);
            }
            if (dist[i] == 1e9) {
                dist[i] = dist[c] + 1;
                bfs.push(i);
            }
        }
    }

    int solMn = 0, solMx = 0;
    for (int i = 0; i < k - 1; ++i) {
        bool other = false, noNext = true;
        for (auto j : opt[p[i]]) {
            if (j == p[i + 1]) {
                noNext = false;
            } else {
                other = true;
            }
        }
        solMx += other;
        solMn += noNext;
    }
    cout << solMn << ' ' << solMx << '\n';
}