/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 08:46:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
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
    const int L = 20;
    vector<int> dep(n);   
    vector<vector<int>> par(n, vector<int>(L));
    function<void(int, int)> Dfs = [&](int v, int p) {
      par[v][0] = p;
      for (int u : g[v]) {
        if (u == p) {
          continue;
        }
        dep[u] = dep[v] + 1;
        Dfs(u, v);          
      }
    };
    Dfs(0, -1);
    for (int j = 1; j < L; j++) {
      for (int i = 0; i < n; i++) {
        if (par[i][j - 1] != -1) {
          par[i][j] = par[par[i][j - 1]][j - 1];
        }
      }
    }
    auto LCA = [&](int u, int v) {
      if (dep[u] < dep[v]) {
        swap(u, v);
      }                       
      for (int j = L - 1; j >= 0; j--) {
        if (par[u][j] != -1 && dep[par[u][j]] >= dep[v]) {
          u = par[u][j];
        }
      }
      for (int j = L - 1; j >= 0; j--) {
        if (par[u][j] != par[v][j]) {
          u = par[u][j];
          v = par[v][j];
        }
      }
      if (u == v) {
        return u;
      } else {
        return par[u][0];  
      }
    };
    auto Dist = [&](int u, int v) {
      return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    };
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return dep[i] > dep[j];
    });
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
      ans[i] = dep[order[0]];
    }
    int x = order[0], y = order[0];
    for (int id = 0; id + 1 < n; id++) {
      int u = order[id];
      if (Dist(x, y) < max(Dist(x, u), Dist(u, y))) {
        if (Dist(x, u) > Dist(u, y)) {
          y = u;
        } else {
          x = u;
        }
      }
      int diam = Dist(x, y);
      int w = dep[order[id + 1]] - (diam + 1) / 2;
      if (w > 0) {
        ans[w] = min(ans[w], dep[order[id + 1]]);
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      ans[i] = min(ans[i], ans[i + 1]); 
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}