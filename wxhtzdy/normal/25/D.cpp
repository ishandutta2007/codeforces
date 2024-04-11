#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    g[x[i]].push_back(y[i]);
    g[y[i]].push_back(x[i]);
  }
  vector<bool> was(n, false);
  function<void(int)> Dfs = [&](int u) {
    was[u] = true;
    for (int v : g[u]) {
      if (!was[v]) {
        Dfs(v);
      }
    }
  };
  vector<int> roots;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      Dfs(i);
      roots.push_back(i);
    }
  }
  int mn = (int) roots.size() - 1;
  vector<bool> taken(n, false);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      g[j].clear();
      was[j] = false;
    }
    for (int j = 0; j < n - 1; j++) {
      if (!taken[j] && i != j) {
        g[x[j]].push_back(y[j]);
        g[y[j]].push_back(x[j]);
      }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (!was[j]) {
        Dfs(j);
        cnt++;
      }
    }
    if (cnt == (int) roots.size()) {
      taken[i] = true;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n - 1; i++) {
    if (taken[i]) {
      ans.push_back(i);
    }
  }
  cout << mn << '\n';
  for (int i = 0; i < mn; i++) {
    cout << x[ans[i]] + 1 << " " << y[ans[i]] + 1 << " " << roots[i] + 1 << " " << roots[i + 1] + 1 << '\n';
  }
  return 0;
}