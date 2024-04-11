/**
 *    author:  tourist
 *    created: 01.11.2020 17:47:09       
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
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
      cin >> color[i];
      --color[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> order;
    vector<int> pv(n, -1);
    function<void(int, int)> Dfs = [&](int v, int pr) {
      pv[v] = pr;
      order.push_back(v);
      for (int u : g[v]) {
        if (u == pr) {
          continue;
        }
        Dfs(u, v);
      }
    };
    Dfs(0, -1);
    const int inf = (int) 1e9;
    vector<vector<int>> dp(n, vector<int>(2));
    int low = 0, high = n;
    while (low < high) {
      int mid = (low + high) >> 1;
      for (int it = n - 1; it >= 0; it--) {
        int v = order[it];
        for (int j = 0; j < 2; j++) {
          dp[v][j] = -1;
          if (color[v] == 1 - j) {
            continue;
          }
          int mx1 = 0;
          int mx2 = 0;
          bool ok = true;
          for (int u : g[v]) {
            if (pv[u] == v) {
              int mn = inf;
              for (int jj = 0; jj < 2; jj++) {
                if (dp[u][jj] != -1) {
                  mn = min(mn, dp[u][jj] + (j != jj));
                }
              }
              if (mn == inf) {
                ok = false;
                break;
              }
              if (mn > mx1) {
                mx2 = mx1;
                mx1 = mn;
              } else {
                if (mn > mx2) {
                  mx2 = mn;
                }
              }
            }
          }
          if (ok && mx1 + mx2 <= mid) {
            dp[v][j] = mx1;
          }
        }
      }
      if (dp[0][0] != -1 || dp[0][1] != -1) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << (low + 3) / 2 << '\n';
  }
  return 0;
}