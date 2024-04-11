#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  vector<int> t(q), x(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i] >> x[i];
    --x[i];
  }
  vector<vector<tuple<int, int, int>>> gg(n);
  const int BLOCK = 5000;
  vector<int> col(n);
  vector<int> lzy(n);
  vector<bool> vv(n);
  vector<int> tmp(n);
  function<void(int)> MakeBlack = [&](int u) {
    if (col[u] == 0) {
      col[u] = 1;
      return;
    }
    lzy[u] += 1;
    for (auto& e : gg[u]) {
      int v = get<0>(e);
      int w = get<1>(e);
      if (w < lzy[u]) {
        MakeBlack(v);
      }
    }
  };
  function<void(int)> MakeWhite = [&](int u) {
    col[u] = 0;
    lzy[u] = 0;
    vv[u] = true;
    for (auto& e : gg[u]) {
      get<1>(e) = get<2>(e);  
      int v = get<0>(e);
      MakeWhite(v);  
    }
  };
  vector<bool> was(n, false);
  function<void(int, int, bool)> Build = [&](int u, int d, bool b) {
    if (was[u]) {
      d = lzy[u];
      b = (b | vv[u]);
    } else {
      col[u] = tmp[u];
      if (b) {
        col[u] = 0;
      } 
      if (d > 0 && col[u] == 0) {
        col[u] = 1;
        d -= 1;
      }
    }
    was[u] = false;
    for (int v : g[u]) {
      Build(v, d, b);
    }
  };           
  for (int i = 0; i < q; i += BLOCK) {                              
    int L = i;
    int R = min(i + BLOCK, q) - 1;
    if (L > R) {
      continue;
    }                       
    for (int j = L; j <= R; j++) {
      was[x[j]] = true;
    }
    for (int j = 0; j < n; j++) {
      tmp[j] = col[j];
      gg[j].clear();
      vv[j] = false;
      lzy[j] = 0;
    }
    function<void(int, int, int, int)> Dfs = [&](int v, int pr, int w, int d) {
      if (was[v]) {
        if (pr != v) {
          gg[pr].emplace_back(v, w, d);
        }
        w = 0;
        d = -1;
        pr = v;
      } else {
        if (col[v] == 0) {
          w += 1;
        }
      }
      for (int u : g[v]) {
        Dfs(u, pr, w, d + 1);
      }
    };                          
    Dfs(0, 0, 0, 0);
    for (int j = L; j <= R; j++) {
      if (t[j] == 1) {
        MakeBlack(x[j]);
      }
      if (t[j] == 2) {
        MakeWhite(x[j]);
      }
      if (t[j] == 3) {
        cout << (col[x[j]] == 0 ? "white" : "black") << '\n';
      }
    }
    Build(0, 0, 0);      
  }
  return 0;
}