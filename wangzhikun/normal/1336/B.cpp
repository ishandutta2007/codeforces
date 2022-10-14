/**
 *    author:  tourist
 *    created: 15.04.2020 17:39:44       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<int>> a(3);
    for (int i = 0; i < 3; i++) {
      a[i].resize(n[i]);
      for (int j = 0; j < n[i]; j++) {
        cin >> a[i][j];
      }
      sort(a[i].begin(), a[i].end());
    }
    long long ans = (long long) 9e18;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n[i]; j++) {
        for (int u = 0; u < 3; u++) {
          if (i == u) {
            continue;
          }
          long long x = -1;
          long long y = -1;
          long long z = a[i][j];
          for (int k = 0; k < 3; k++) {
            if (k == i) {
              continue;
            }
            if (k == u) {
              auto it = lower_bound(a[k].begin(), a[k].end(), a[i][j]);
              if (it != a[k].end()) {
                x = *it;
              }
            } else {
              auto it = upper_bound(a[k].begin(), a[k].end(), a[i][j]);
              if (it != a[k].begin()) {
                y = *prev(it);
              }
            }
          }
          if (x < 0 || y < 0) {
            continue;
          }
          ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}