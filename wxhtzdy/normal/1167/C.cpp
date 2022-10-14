/**
 *    author:  milos
 *    created: 23.02.2021 16:52:56       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int j = 0; j < k; j++) {
      cin >> a[j];
      --a[j];
      if (j > 0) {
        g[a[j]].push_back(a[j - 1]);
        g[a[j - 1]].push_back(a[j]);
      }
    }
  }
  vector<bool> was(n, false);
  vector<int> id(n), sz(n);
  int comp = 0;
  function<void(int)> Dfs = [&](int u) {
    was[u] = true;
    id[u] = comp;
    sz[comp]++;
    for (int j : g[u]) {
      if (!was[j]) {
        Dfs(j);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      Dfs(i);
      comp++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << sz[id[i]] << " ";
  }
  cout << '\n';
  return 0;
}