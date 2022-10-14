/**
 *    author:  milos
 *    created: 02.04.2021 19:23:56       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int MAX = 5e3 + 5;
  vector<vector<int>> pos(MAX);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  vector<vector<int>> dp(n, vector<int>(n));
  vector<int> pref(n);
  for (int i = 0; i < n; i++) {
    vector<int> was(MAX, false);
    int xr = 0, mn = n, mx = 0;
    for (int j = i; j >= 0; j--) {
      if (!was[a[j]]) {
        xr ^= a[j];
        was[a[j]] = true;
        mx = max(mx, pos[a[j]].back());
        mn = min(mn, pos[a[j]][0]);
      }
      if (i >= mx && j <= mn) {
        dp[i][j] = (j > 0 ? pref[j - 1] : 0) + xr;  
      }
    }
    pref[i] = *max_element(dp[i].begin(), dp[i].end());
    if (i > 0) {
      pref[i] = max(pref[i], pref[i - 1]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
  }
  cout << ans << '\n';
  return 0;
}