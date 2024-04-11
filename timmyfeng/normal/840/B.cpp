#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> d(n);
  for (auto &i : d) {
    cin >> i;
  }

  vector<vector<array<int, 2>>> adj(n);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  if (count(d.begin(), d.end(), 1) % 2 == 1) {
    int i = find(d.begin(), d.end(), -1) - d.begin();
    if (i == n) {
      cout << -1 << "\n";
      exit(0);
    }
    d[i] = 1;
  }

  vector<int> ans;
  vector<bool> visited(n);
  auto dfs = [&](auto self, int u) -> bool {
    visited[u] = true;
    bool res = (d[u] == 1);
    for (auto [c, i] : adj[u]) {
      if (!visited[c]) {
        int child = self(self, c);
        if (child) {
          ans.push_back(i);
        }
        res ^= child;
      }
    }
    return res;
  };
  dfs(dfs, 1);

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}