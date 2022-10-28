#include <bits/stdc++.h>
using namespace std;

vector<vector<array<int, 2>>> adj;
vector<int64_t> cost;
vector<int64_t> ans;
vector<int> color;
vector<int> dep;

int edge_i, edge_u, edge_v;
int64_t bal;

void dfs_dep(int u, int p) {
  if (dep[u] % 2 == 0) {
    bal += cost[u];
  } else {
    bal -= cost[u];
  }

  color[u] = 1;
  for (auto [c, i] : adj[u]) {
    if (c != p) {
      if (color[c] == 1 && dep[u] % 2 == dep[c] % 2) {
        edge_i = i;
        edge_u = u;
        edge_v = c;
      } else if (color[c] == 0) {
        dep[c] = dep[u] + 1;
        dfs_dep(c, u);
      }
    }
  }
  color[u] = 2;
}

void dfs_solve(int u) {
  color[u] = 1;
  for (auto [c, i] : adj[u]) {
    if (color[c] == 2) {
      dfs_solve(c);
      ans[i] = cost[c];
      cost[u] -= ans[i];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  color.resize(n + 1);
  cost.resize(n + 1);
  dep.resize(n + 1);
  adj.resize(n + 1);
  ans.resize(m + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  dfs_dep(1, 0);

  if (bal != 0 && edge_i == 0) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";

  if (dep[edge_u] % 2 == 0) {
    ans[edge_i] = bal / 2;
  } else {
    ans[edge_i] = -bal / 2;
  }
  cost[edge_u] -= ans[edge_i];
  cost[edge_v] -= ans[edge_i];

  dfs_solve(1);

  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << "\n";
  }
}