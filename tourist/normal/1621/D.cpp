/**
 *    author:  tourist
 *    created: 03.01.2022 17:48:10       
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
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2 * n));
    long long ans = 0;
    for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        cin >> a[i][j];
        if (i >= n && j >= n) {
          ans += a[i][j];
        }
      }
    }
    int add = min({a[n][0], a[n][n - 1], a[2 * n - 1][0], a[2 * n - 1][n - 1]});
    add = min({add, a[0][n], a[n - 1][n], a[0][2 * n - 1], a[n - 1][2 * n - 1]});
    cout << ans + add << '\n';
  }
  return 0;
}