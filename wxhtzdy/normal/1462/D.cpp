/**
 *  author: milos
 *  created: 15.12.2020 15:49:38
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
    vector<int> all;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tmp += a[i];
      all.push_back(tmp);
    }
    int ans = n;
    for (int c : all) {
      int cnt = 0, sum = 0;
      bool ok = 1;
      for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > c) {
          ok = 0;
          break;
        }
        if (sum == c) {
          sum = 0;
          cnt++;
        }
      }
      if (sum < c && sum > 0) ok = 0;
      if (ok) {
        ans = min(ans, n - cnt);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}