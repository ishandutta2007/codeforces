/**
 *  author: milos
 *  created: 08.01.2021 19:43:09
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += 1;
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans += 1;
    }
    int old = ans;
    for (int i = 0; i < n; i++) {
      for (int j : {-1, 1}) {
        int k = i + j;
        if (k < 0 || k >= n) {
          continue;
        }
        int b = a[i], nans = old;
        for (int jj = i - 1; jj <= i + 1; jj++) {
          if (jj <= 0 || jj >= n - 1) {
            continue;
          }
          if (a[jj] > a[jj - 1] && a[jj] > a[jj + 1]) nans -= 1;
          if (a[jj] < a[jj - 1] && a[jj] < a[jj + 1]) nans -= 1;
        }
        a[i] = a[k];
        for (int jj = i - 1; jj <= i + 1; jj++) {
          if (jj <= 0 || jj >= n - 1) {
            continue;
          }
          if (a[jj] > a[jj - 1] && a[jj] > a[jj + 1]) nans += 1;
          if (a[jj] < a[jj - 1] && a[jj] < a[jj + 1]) nans += 1;
        }
        a[i] = b;
        ans = min(ans, nans);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}