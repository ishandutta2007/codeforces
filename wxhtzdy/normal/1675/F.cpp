/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 16:36:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    --x; --y;
    vector<vector<int>> go(n, vector<int>(2));
    go[y][0] = 1;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      --a;
      go[a][1] = 1;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }            
    int ans = 0;
    function<void(int, int)> Dfs = [&](int u, int p) {
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }    
        Dfs(v, u);
        go[u][0] |= go[v][0];
        go[u][1] |= go[v][1];
        if (go[v][0]) {
          ans += 1;
        } else {
          if (go[v][1]) {
            ans += 2;
          }
        }
      }        
    };
    Dfs(x, x);
    cout << ans << '\n';
  }                                                                    
  return 0;
}