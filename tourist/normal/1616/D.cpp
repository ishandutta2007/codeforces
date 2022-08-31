/**
 *    author:  tourist
 *    created: 29.12.2021 18:47:28       
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
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
      a[i] -= x;
    }
    const int inf = (int) 1e9;
    vector<int> dp(4, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      vector<int> new_dp(4, -inf);
      for (int t = 0; t < 4; t++) {
        if (dp[t] < 0) {
          continue;
        }
        int p0 = (t & 1);
        int p1 = ((t >> 1) & 1);
        for (int p2 = 0; p2 < 2; p2++) {
          if (i > 0 && p2 > 0 && p1 > 0 && a[i] + a[i - 1] < 0) {
            continue;
          }
          if (i > 1 && p2 > 0 && p1 > 0 && p0 > 0 && a[i] + a[i - 1] + a[i - 2] < 0) {
            continue;
          }
          new_dp[p1 + 2 * p2] = max(new_dp[p1 + 2 * p2], dp[t] + p2);
        }
      }
      swap(dp, new_dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}