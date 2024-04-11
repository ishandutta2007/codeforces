#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int visited[N], color[N], odd[N], even[N];
vector<pair<int, int>> odd_edges;
vector<int> adj[N], span[N];

void dfs(int u, int p = -1) {
    visited[u] = 1;
    for (auto c : adj[u]) {
        if (c == p) continue;
        if (visited[c] == 0) {
            span[u].push_back(c);
            color[c] = color[u] ^ 1;
            dfs(c, u);
            odd[u] += odd[c];
            even[u] += even[c];
        } else if (visited[c] == 1) {
            if (color[u] == color[c]) {
                odd_edges.push_back({c, u});
                ++odd[u], --odd[c];
            } else {
                ++even[u], --even[c];
            }
        }
    }
    visited[u] = 2;
}

void invert(int u) {
    for (auto c : span[u]) invert(c);
    color[u] ^= 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        fill(adj, adj + n, vector<int>());

        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        fill(span, span + n, vector<int>());
        fill(visited, visited + n, 0);
        fill(even, even + n, 0);
        fill(odd, odd + n, 0);
        odd_edges.clear();

        dfs(0);

        if (odd_edges.size() <= 1u) {
            for (int i = 0; i < n; ++i) {
                for (auto j : adj[i]) {
                    if (color[i] == 0 && color[j] == 0) {
                        for (int k = 0; k < n; ++k) color[k] ^= 1;
                    }
                }
            }
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << color[i];
            }
            cout << "\n";
            continue;    
        }

        bool found = false;
        for (int i = 1; i < n; ++i) {
            if (even[i] == 0 && odd[i] == (int) odd_edges.size()) {
                found = true;
                invert(i);
                break;
            }
        }

        if (found) {
            for (int i = 0; i < n; ++i) {
                for (auto j : adj[i]) {
                    if (color[i] == 0 && color[j] == 0) {
                        for (int k = 0; k < n; ++k) color[k] ^= 1;
                    }
                }
            }
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << color[i];
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}