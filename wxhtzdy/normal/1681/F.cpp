/**
 *    author:  wxhtzdy
 *    created: 23.05.2022 16:48:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    --u; --v; --x;
    g[u].emplace_back(v, x);
    g[v].emplace_back(u, x);
  }
  vector<bool> was(n, false);
  vector<int> sz(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    sz[u] = 1;
    for (auto e : g[u]) {
      int v = e.first;
      if (v == p || was[v]) {
        continue;
      }
      Dfs(v, u);
      sz[u] += sz[v];
    }
  };                  
  function<int(int, int, int)> Cen = [&](int u, int p, int n) {
    for (auto e : g[u]) {
      int v = e.first;
      if (v != p && !was[v] && sz[v] * 2 > n) {
        return Cen(v, u, n);
      }
    }
    return u;
  };
  function<int(int)> Find = [&](int u) {
    Dfs(u, u);
    return Cen(u, u, sz[u]);
  };
  long long ans = 0;
  long long tot = 0;
  long long ft = 0;
  vector<int> cnt(n);
  vector<int> aux(n);
  vector<int> vec;
  function<void(int, int)> Solve = [&](int u, int p) {
    ans += ft;
    for (auto e : g[u]) {
      int v = e.first;
      if (v == p || was[v]) {
        continue;
      }
      vec.push_back(e.second);
      cnt[e.second]++;
      if (cnt[e.second] == 1) {
        ft += tot - aux[e.second];
      }
      if (cnt[e.second] == 2) {
        ft -= tot - aux[e.second];
      }
      Solve(v, u);
      if (cnt[e.second] == 2) {
        ft += tot - aux[e.second];
      }
      if (cnt[e.second] == 1) {
        ft -= tot - aux[e.second];
      }
      cnt[e.second]--;
    }
  };
  function<void(int, int, int)> Travel = [&](int u, int p, int coeff) {
    for (auto e : g[u]) {
      int v = e.first;
      if (was[v] || v == p) {
        continue;
      }
      cnt[e.second] += 1;
      if (cnt[e.second] == 1) {
        aux[e.second] += sz[v] * coeff;
      }
      Travel(v, u, coeff);
      cnt[e.second] -= 1;
    }
  };
  function<void(int)> Decomp = [&](int u) {
    u = Find(u);
    Dfs(u, u);
    was[u] = true; 
    tot = sz[u];
    for (auto e : g[u]) {
      if (was[e.first]) {
        continue;
      }     
      aux[e.second] += sz[e.first];
      cnt[e.second] += 1;
      Travel(e.first, u, +1);
      cnt[e.second] -= 1; 
//      tot += sz[e.first];
    }
    for (auto e : g[u]) {
      if (was[e.first]) {
        continue;
      }
      cnt[e.second] += 1;
      aux[e.second] -= sz[e.first];                   
      Travel(e.first, u, -1);
      cnt[e.second] -= 1;
      tot -= sz[e.first];
      cnt[e.second]++;             
      vec.push_back(e.second);
      ft += tot - aux[e.second];
      Solve(e.first, u);
      ft -= tot - aux[e.second];
      tot += sz[e.first];
      cnt[e.second]--;
      cnt[e.second] += 1;
      Travel(e.first, u, +1);
      cnt[e.second] -= 1;
      aux[e.second] += sz[e.first];
    }       
    for (int x : vec) {
      aux[x] = 0;
    }
    vec.clear();
    for (auto e : g[u]) {
      int v = e.first;
      if (was[v]) {
        continue;
      }
      Decomp(v);
    }                   
  };
  Decomp(0);
  cout << ans << '\n';                                                            
  return 0;
}