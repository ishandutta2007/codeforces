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
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[t - 1].push_back(i);
  }
  vector<int> mark(n, -1);
  vector<bool> used(n);
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    for (int x : a[i]) {
      for (int u : g[x]) {
        if (mark[u] != -1) {
          used[mark[u]] = true;
        }
      }
      int t = 0;
      while (used[t]) t++;
      for (int u : g[x]) {
        if (mark[u] != -1) {
          used[mark[u]] = false;
        }
      }
      if (t != i) {
        cout << "-1\n";
        return 0;
      }
      mark[x] = t;
      res.push_back(x);
    }
  }
  for (int u : res) cout << u + 1 << " ";
  cout << "\n";
}