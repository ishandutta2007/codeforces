#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> col(n);
  for (int i = 0; i < n; i++) {
    cin >> col[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int mx = 0, j = 0;
  function<void(int, int, int)> Dfs = [&](int u, int p, int dep) {
    if (dep > mx) {
      mx = dep;
      j = u;
    }
    for (int v : g[u]) {
      if (v == p) continue;
      if (col[v] != col[u]) Dfs(v, u, dep + 1);
      else Dfs(v, u, dep);
    }
  };
  for (int i = 0; i < 2; i++) {
    mx = 0;
    Dfs(j, -1, 0);
  }
  cout << (mx + 1) / 2 << '\n';
  return 0;
}