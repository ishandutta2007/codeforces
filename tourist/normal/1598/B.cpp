/**
 *    author:  tourist
 *    created: 10.10.2021 12:06:55       
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
        int ka = 0;
        int kb = 0;
        int kab = 0;
        for (int i = 0; i < n; i++) {
          if (a[i][x] == 1 && a[i][y] == 1) {
            kab += 1;
          } else {
            if (a[i][x] == 1) {
              ka += 1;
            }
            if (a[i][y] == 1) {
              kb += 1;
            }
          }
        }
        if (ka + kb + kab == n && ka + kab >= n / 2 && kb + kab >= n / 2) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}