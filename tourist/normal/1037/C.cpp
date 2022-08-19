/**
 *    author:  tourist
 *    created: 02.09.2018 17:38:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  cin >> b;
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + (a[i - 1] != b[i - 1]);
    if (i >= 2 && a[i - 2] == b[i - 1] && a[i - 1] == b[i - 2]) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}