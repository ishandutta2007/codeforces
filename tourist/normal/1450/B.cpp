/**
 *    author:  tourist
 *    created: 06.12.2020 17:36:44       
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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        if (d > k) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}