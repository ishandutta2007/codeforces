#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dep(n, -1);
  vector<int> fa(n, -1);

  int k = 1;
  while (k * k < n) k++;

  function<void(int, int)> Dfs = [&](int x, int p) {
    dep[x] = ~p ? dep[p] + 1 : 0;
    fa[x] = p;
    for (int u : g[x]) {
      if (u == p) continue;
      if (dep[u] == -1) {
        Dfs(u, x);
      } else {
        if (dep[x] - dep[u] + 1 >= k) {
          cout << "2\n" << dep[x] - dep[u] + 1 << "\n";
          while (true) {
            cout << x + 1 << " ";
            if (x == u) break;
            x = fa[x];
          }
          cout << "\n";
          exit(0);
        }
      }
    }
  };

  Dfs(0, -1);
  vector<vector<int>> nd(k - 1);
  for (int i = 0; i < n; ++i) {
    nd[dep[i] % (k - 1)].push_back(i);
  }
  for (int i = 0; i < k - 1; ++i) {
    if (nd[i].size() >= k) {
      cout << "1\n";
      for (int j = 0; j < k; ++j) cout << nd[i][j] + 1 << " ";
      cout << "\n";
      return 0;
    }
  }
}