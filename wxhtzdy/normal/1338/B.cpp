/**
 *    author:  wxhtzdy
 *    created: 23.01.2022 20:01:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int x;
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() != 1) {
      x = i;
    }
  }
  int mn = 1, mx = n - 1;
  vector<int> dep(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    int ch = 0;
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      dep[v] = dep[u] + 1;
      Dfs(v, u);
      if ((int) g[v].size() == 1) {
        ch += 1;
      }
    }
    mx -= max(0, ch - 1);
  };
  Dfs(x, x);
  vector<int> l;       
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() == 1) {
      l.push_back(i);
    }
  }
  for (int i = 0; i + 1 < (int) l.size(); i++) {
    if (dep[l[i]] % 2 != dep[l[i + 1]] % 2) {
      mn = 3;
    }
  }
  cout << mn << " " << mx << '\n';                                     
  return 0;
}