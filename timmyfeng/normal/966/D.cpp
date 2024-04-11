#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  set<array<int, 2>> edges;
  vector<vector<int>> adj(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.insert({u, v});
    edges.insert({v, u});
  }

  vector<int> dist(n + 1, -1);
  vector<int> par(n + 1);
  queue<int> que;
  que.push(1);
  dist[1] = 0;

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int c : adj[u]) {
      if (c != par[u]) {
        if (dist[c] == -1) {
          dist[c] = dist[u] + 1;
          que.push(c);
          par[c] = u;
        }
      }
    }
  }

  vector<int> direct;
  int z = n;
  while (z != 0) {
    direct.push_back(z);
    z = par[z];
  }
  reverse(direct.begin(), direct.end());

  vector<bool> neighbor(n + 1);
  for (int u : adj[1]) {
    neighbor[u] = true;
  }

  vector<int> shortcut;
  for (int u : adj[1]) {
    for (int v : adj[u]) {
      if (!neighbor[v] && v != 1) {
        shortcut = {1, u, v, 1, n};
      }
    }
  }

  vector<int> longcut;
  vector<bool> visited(n + 1);
  for (int i = 2; i <= n; ++i) {
    if (neighbor[i] && !visited[i]) {
      visited[i] = true;
      vector<int> all;
      all.push_back(i);
      int ptr = 0;

      while (ptr < int(all.size())) {
        int u = all[ptr];
        ++ptr;
        for (auto c : adj[u]) {
          if (neighbor[c] && !visited[c]) {
            visited[c] = true;
            all.push_back(c);
          }
        }
      }

      for (auto j : all) {
        for (auto k : all) {
          if (j != k && edges.count({j, k}) == 0) {
            set<int> first(adj[j].begin(), adj[j].end());
            int u = 0;
            for (auto v : adj[k]) {
              if (v != 1 && first.count(v) != 0) {
                u = v;
                break;
              }
            }
            longcut = {1, j, u, k, j, n};
            goto done;
          }
        }
      }
    }
  } done:

  if (!shortcut.empty() && (dist[n] == -1 || dist[n] >= 4)) {
    cout << 4 << "\n";  
    for (auto i : shortcut) {
      cout << i << " ";
    }
    cout << "\n";
  } else if (!longcut.empty() && (dist[n] == -1 || dist[n] >= 5)) {
    cout << 5 << "\n";
    for (auto i : longcut) {
      cout << i << " ";
    }
    cout << "\n";
  } else if (dist[n] != -1) {
    cout << dist[n] << "\n";
    for (auto i : direct) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    cout << -1 << "\n";
  }
}