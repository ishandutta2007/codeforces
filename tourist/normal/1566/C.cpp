/**
 *    author:  tourist
 *    created: 12.09.2021 17:38:57       
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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      bool has0 = false;
      bool has1 = false;
      for (int j = i - 1; j >= i - 10 && j >= 0; j--) {
        for (int x = 0; x < 2; x++) {
          if (a[x][j] == '0') has0 = true;
          else has1 = true;
        }
        int mex = (!has0 ? 0 : (!has1 ? 1 : 2));
        dp[i] = max(dp[i], dp[j] + mex);
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}