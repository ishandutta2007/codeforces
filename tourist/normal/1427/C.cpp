/**
 *    author:  tourist
 *    created: 10.10.2020 18:03:47       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  vector<int> dp(n);
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    if (x[i] + y[i] > t[i]) {
      dp[i] = -1;
    } else {
      int from = max(0, i - 2 * r);
      dp[i] = 1 + pref[from];
      for (int j = i - 1; j >= from; j--) {
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[j] <= t[i] && dp[j] != -1) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    pref[i + 1] = max(pref[i], dp[i]);
  }
  cout << pref[n] << '\n';
  return 0;
}