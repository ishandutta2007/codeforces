/**
 *  author: milos
 *  created: 04.01.2021 15:42:27
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
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i + a[i] < n){
        dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i]);
        ans = max(ans, dp[i + a[i]]);
      } else {
        ans = max(ans, dp[i] + a[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}