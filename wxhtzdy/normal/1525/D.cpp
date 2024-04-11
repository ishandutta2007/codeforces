#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> x, y;
  long long inf = 1e17;
  vector<vector<long long>> dp(n, vector<long long>(n, inf));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      x.push_back(i);
    } else {
      y.push_back(i);
    }
  }
  if (x.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  dp[0][0] = 0;
  /*for (int i = 0; i < (int) x.size(); i++) {
    vector<long long> new_dp(n, inf);
    for (int j = 0; j < (int) y.size(); j++) {
      new_dp[j + 1] = min((i == 0 ? inf : dp[i - 1][j + 1]), (i == 0 ? 0 : dp[i - 1][j]) + abs(x[i] - y[j]));
    }
    swap(new_dp, dp[i]);
  }*/
  for (int i = 0; i < (int) y.size(); i++) {
    vector<long long> new_dp(n, inf);
    new_dp[0] = 0;
    if (i != 0) {
      new_dp = dp[i - 1];
    }
    for (int j = 0; j < (int) x.size(); j++) {
      new_dp[j + 1] = min(new_dp[j + 1], (i == 0 ? (j == 0 ? 0LL : inf) : dp[i - 1][j]) + abs(x[j] - y[i]));
    }
    swap(dp[i], new_dp);
  }
  long long ans = inf;
  for (int i = (int) x.size() - 1; i < n; i++) {
    ans = min(ans, dp[i][(int) x.size()]);
  }
  cout << ans << '\n';
  return 0;
}