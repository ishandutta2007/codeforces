#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;

vector<array<int, 3>> adj[N];
bool visited[N];

vector<array<int, 2>> dfs_path(int u, int v) {
  visited[u] = true;
  for (auto [c, w, i] : adj[u]) {
    if (!visited[c]) {
      if (c == v) {
        return {{w, i}};
      } else {
        auto child = dfs_path(c, v);
        if (!child.empty()) {
          child.push_back({w, i});
          return child;
        }
      }
    }
  }
  return {};
}

int low[N], in[N], out[N], timer, ban;
int s, t;

array<int, 2> dfs_low(int u, int p = 0) {
  array<int, 2> mini = {INT_MAX, 0};
  in[u] = low[u] = ++timer;
  visited[u] = true;

  for (auto [c, w, i] : adj[u]) {
    if (i != p && i != ban) {
      if (visited[c]) {
        low[u] = min(low[u], in[c]);
      } else {
        mini = min(mini, dfs_low(c, i));
        low[u] = min(low[u], low[c]);
        if (low[c] > in[u]) {
          if (in[c] <= in[t] && out[t] <= out[c]) {
            mini = min(mini, array<int, 2>{w, i});
          }
        }
      }
    }
  }

  out[u] = timer;
  return mini;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> s >> t;

  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w, i});
    adj[v].push_back({u, w, i});
  }

  vector<array<int, 2>> path = dfs_path(s, t);
  int cost = INT_MAX;
  vector<int> edges;

  if (path.empty()) {
    cout << 0 << "\n";
    cout << 0 << "\n";
    cout << "\n";
    exit(0);
  }

  for (auto [w1, i] : path) {
    fill(visited + 1, visited + n + 1, false);
    ban = i;

    auto [w2, j] = dfs_low(s);
    if (!visited[t] && w1 < cost) {
      cost = w1;
      edges = {i};
    } else if (w2 < INT_MAX && w1 + w2 < cost) {
      cost = w1 + w2;
      edges = {i, j};
    }
  }

  if (cost == INT_MAX) {
    cout << -1 << "\n";
  } else {
    cout << cost << "\n";
    cout << edges.size() << "\n";
    for (auto i : edges) {
      cout << i << " ";
    }
    cout << "\n";
  }
}