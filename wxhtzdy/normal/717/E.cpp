/**
 *    author:  wxhtzdy
 *    created: 18.09.2022 10:50:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);   
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> f(n);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    f[v] = (a[v] == 1 ? 0 : 1);
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      Dfs(u, v);
      f[v] += f[u];
    }      
  };
  Dfs(0, 0);
  vector<int> ans;
  auto Change = [&](int v) {
    f[v] -= (a[v] == 1 ? 0 : 1);
    a[v] = (a[v] == -1 ? +1 : -1);
    f[v] += (a[v] == 1 ? 0 : 1);
  };
  function<void(int, int)> Solve = [&](int v, int pr) {
    ans.push_back(v);
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      if (f[u] > 0) {
        f[v] -= f[u];
        Change(u);
        f[v] += f[u];
        f[v] -= f[u];
        Solve(u, v);
        f[v] += f[u];
        ans.push_back(v);
        Change(v);
      }
      if (f[u] > 0) {
        f[v] -= f[u];
        Change(u);
        f[v] += f[u];
        f[v] -= f[u];
        Solve(u, v);
        f[v] += f[u];
        ans.push_back(v);
        Change(v);
      }
      if (f[u] > 0) {
        f[v] -= f[u];
        Change(u);
        f[v] += f[u];
        f[v] -= f[u];
        Solve(u, v);
        f[v] += f[u];
        ans.push_back(v);
        Change(v);
      }
    }
  };
  Solve(0, 0);
  if (a[0] == -1) {
    assert(ans.back() == 0);
    ans.push_back(g[0][0]);
    ans.push_back(0);
    ans.push_back(g[0][0]);
    Change(0);
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}