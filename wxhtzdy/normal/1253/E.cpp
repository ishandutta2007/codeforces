/**
 *  author: milos
 *  created: 07.01.2021 17:23:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> s[i];
  }
  const int inf = 1e9;
  vector<int> dp(m + 1, inf);
  dp[m] = 0;
  int cnt = 1;
  for (int i = m - 1; i >= 0; i--) {
    dp[i] = cnt;
    cnt += 1;
    for (int j = 0; j < n; j++) {
      int l = max(0, x[j] - s[j]), r = min(m, x[j] + s[j]);
      if (l - 1 <= i && i <= r - 1) {
        dp[i] = min(dp[i], dp[i + 1]);
      }
      if (i < l) {
        dp[i] = min(dp[i], l - i - 1 + dp[min(m, r + l - i - 1)]);  
      }
    }
  }
  cout << dp[0] << '\n'; 
  return 0;
}