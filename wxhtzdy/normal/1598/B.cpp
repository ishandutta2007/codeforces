/**
 *    author: m371
 *    created: 10.10.2021 12:53:04
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
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    bool ok = false;
    for (int x = 0; x < 5; x++) {
      for (int y = x + 1; y < 5; y++) {
        vector<int> cnt(2);
        int bonus = 0;
        bool can = true;
        for (int i = 0; i < n; i++) {
          if (a[i][x] == 1 && a[i][y] == 0) cnt[0]++;
          if (a[i][y] == 1 && a[i][x] == 0) cnt[1]++;
          if (a[i][x] == 1 && a[i][y] == 1) bonus++;
          if (a[i][x] == 0 && a[i][y] == 0) can = false;
        }
        int need = n / 2 - cnt[0] + n / 2 - cnt[1];
        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && bonus >= need && can) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}