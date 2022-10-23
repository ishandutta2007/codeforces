/**
 *    author:  tourist
 *    created: 07.10.2022 18:50:28       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    const int inf = (int) 1.01e9;
    vector<vector<int>> g0(n, vector<int>(n, inf));
    vector<vector<int>> g1(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
      g0[i][i] = g1[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      g0[a][b] = g0[b][a] = 1;
      g1[a][b] = min(g1[a][b], c);
      g1[b][a] = min(g1[b][a], c);
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          g0[i][j] = min(g0[i][j], g0[i][k] + g0[k][j]);
        }
      }
    }
    const long long infll = (long long) 1e18;
    long long ans = infll;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && g1[i][j] != inf) {
          {
            long long ft = (long long) g1[i][j] * (g0[0][i] + 1 + g0[j][n - 1]);
            ans = min(ans, ft);
          }
          for (int k = 0; k < n; k++) {
            long long ft = (long long) g1[i][j] * (g0[k][i] + 1 + g0[0][k] + g0[k][n - 1] + 1);
            ans = min(ans, ft);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}