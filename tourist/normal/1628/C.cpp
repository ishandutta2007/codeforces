/**
 *    author:  tourist
 *    created: 22.01.2022 17:52:17       
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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int rot = 0; rot < 2; rot++) {
      for (int i = 0; i < n; i += 4) {
        int x = i;
        int y = 0;
        while (x >= 0 && x < n && y >= 0 && y < n) {
          ans ^= a[x][y];
          x -= 2;
          y += 2;
        }
      }
      for (int j = (n % 4 == 0 ? 1 : 3); j < n; j += 4) {
        int x = n - 1;
        int y = j;
        while (x >= 0 && x < n && y >= 0 && y < n) {
          ans ^= a[x][y];
          x -= 2;
          y += 2;
        }
      }
      reverse(a.begin(), a.end());
    }
    cout << ans << '\n';
  }
  return 0;
}