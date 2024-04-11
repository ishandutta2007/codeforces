#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> type(m), x(m), y(m);
  vector<vector<int>> g_col(n);
  for (int i = 0; i < m; i++) {
    cin >> type[i] >> x[i] >> y[i];
    --x[i]; --y[i];
    g_col[x[i]].push_back(y[i]);
    g_col[y[i]].push_back(x[i]);
  }
  vector<bool> was(n, false);
  string dir = string(n, 'L');
  function<void(int)> Dfs1 = [&](int v) {
    was[v] = true;      
    for (int u : g_col[v]) {
      if (was[u] && dir[u] == dir[v]) {
        cout << "NO" << '\n';
        exit(0);
      }
      if (was[u]) {
        continue;
      }
      dir[u] = dir[v] ^ 'L' ^ 'R';
      Dfs1(u);
    }
  };
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      Dfs1(i);
    }
  }
  vector<vector<int>> g(n); 
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    assert(dir[x[i]] != dir[y[i]]);
    if (dir[x[i]] == 'R') {
      swap(x[i], y[i]);
    }
    if (type[i] == 1) {
      deg[y[i]] += 1;
      g[x[i]].push_back(y[i]);
    } else {
      deg[x[i]] += 1;
      g[y[i]].push_back(x[i]);
    }
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }             
  for (int b = 0; b < que.size(); b++) {
    int v = que[b];
    for (int i : g[v]) {
      deg[i] -= 1;
      if (deg[i] == 0) {
        que.push_back(i);
      }
    }
  }
  if ((int) que.size() < n) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<int> res(n);
  for (int i = 0; i < que.size(); i++) {
    res[que[i]] = i;
  }
  cout << "YES" << '\n';                  
  for (int i = 0; i < n; i++) {
    cout << dir[i] << " " << res[i] << '\n';
  }
  return 0;
}