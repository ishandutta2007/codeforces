/**
 *    author:  milos
 *    created: 10.03.2021 21:42:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;              
  vector<int> u(m), v(m);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
    g[u[i]].emplace_back(v[i], i);
    g[v[i]].emplace_back(u[i], i); 
  }           
  vector<bool> was(n, false), edge(m, false);
  vector<int> in(n), out(n);
  int t = 1;
  bool ok = true;
  vector<pair<int, int>> ans;
  function<void(int, int)> Dfs = [&](int node, int p) {
    out[node] = in[node] = t++;
    was[node] = true;
    for (auto e : g[node]) {
      if (e.first == p) {
        continue;
      }
      if (!was[e.first]) {
        Dfs(e.first, node);
      } else {
        out[node] = min(out[node], in[e.first]);
        if (!edge[e.second]) {
          ans.emplace_back(node, e.first);
        }
        edge[e.second] = true; 
        continue;
      }
      out[node] = min(out[node], out[e.first]);
      if (!edge[e.second]) {
        ans.emplace_back(node, e.first);
      }
      edge[e.second] = true; 
      if (out[e.first] > in[node]) {
        ok = false;
      }   
    }
  };
  Dfs(0, -1);
  if (!ok) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }
  return 0;
}