/**
 *    author:  wxhtzdy
 *    created: 15.06.2022 18:45:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> g(n);
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.emplace_back(u, v);
  }  
  vector<int> dep(n);
  vector<int> cnt(n);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    dep[v] = dep[pr] + 1;
    cnt[v] = (c[v] == 1);
    for (int u : g[v]) {
      if (u != pr) {
        Dfs(u, v);
        cnt[v] += cnt[u];
      }
    }
  };
  Dfs(0, 0);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  int s = accumulate(c.begin(), c.end(), 0);
  for (auto &e : edges) {    
    int u = e.first;
    int v = e.second;
    if (dep[u] > dep[v]) {
      swap(u, v);
    }              
    if (c[v] == 1 || cnt[v] >= 2) {
      g[v].push_back(u);
    }
    if (c[u] == 1 || s - cnt[v] >= 2) {
      g[u].push_back(v);
    }
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (c[i] == 1) {
      que.push_back(i);
    }
  }              
  vector<int> ans(n);     
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    ans[i] = 1;
    for (int j : g[i]) {
      if (ans[j] == 0) {
        ans[j] = 1;
        que.push_back(j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1]; 
  }
  return 0;
}