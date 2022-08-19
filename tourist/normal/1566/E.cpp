/**
 *    author:  tourist
 *    created: 12.09.2021 18:12:12       
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
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int ans = 0;
    function<int(int, int)> Dfs = [&](int v, int pr) {
      int s = 0;
      for (int u : g[v]) {
        if (u == pr) {
          continue;
        }
        s += Dfs(u, v);
      }
      if (s == 0) {
        return 1;
      }
      ans += 1;
      return 0;
    };
    int ret = Dfs(0, -1);
    if (ret == 0) {
      cout << n - 2 * ans + 1 << '\n';
    } else {
      cout << n - 2 * ans << '\n';
    }
  }
  return 0;
}