/**
 *    author:  wxhtzdy
 *    created: 27.07.2022 13:21:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, s;
  cin >> n >> m >> s;
  --s;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
  }
  vector<int> par(n, -1);      
  vector<int> tin(n);
  vector<int> tout(n);
  int T = 0;
  int x = -1, y = -1;
  auto isPar = [&](int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
  };
  {
    vector<bool> was(n);
    function<void(int)> Dfs = [&](int v) {
      was[v] = true;
      tin[v] = ++T;
      for (int u : g[v]) {
        if (!was[u]) {
          Dfs(u);
        }
      }
      tout[v] = T;
    };
    Dfs(s);
  }
  function<void(int, int, int)> Dfs = [&](int v, int pr, int sec) {
    par[v] = pr;
    if (sec == -1 && v != s) {
      sec = v;
    }
    for (int u : g[v]) {
      if (par[u] == -1) {
        Dfs(u, v, sec);
      } else {           
        if (u != s && (sec == -1 || !isPar(sec, u))) {
          x = u;
          y = v;
        }
      }
    }
  };
  Dfs(s, s, -1);
  if (x == -1) {
    cout << "Impossible" << '\n';                                           
    return 0;
  }
  cout << "Possible" << '\n';           
  {
    vector<int> path;
    int f = x;
    while (f != s) {
      path.push_back(f);
      f = par[f];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    cout << (int) path.size() << '\n';
    for (int i = 0; i < (int) path.size(); i++) {
      cout << path[i] + 1 << " ";
    }
    cout << '\n';
  }
  {
    vector<int> path(1, x);
    int f = y;
    while (f != s) {
      path.push_back(f);
      f = par[f];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    cout << (int) path.size() << '\n';
    for (int i = 0; i < (int) path.size(); i++) {
      cout << path[i] + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}