/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 11:56:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> x(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> c[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (x[i] != x[j]) {
      return x[i] < x[j];
    } else {
      return c[i] < c[j];
    }
  });
  vector<long long> dp(n + 1, 1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    long long sum = c[order[i]];
    dp[i + 1] = min(dp[i + 1], dp[i] + c[order[i]]);    
    for (int j = i + 1; j < n; j++) {
      sum += abs(x[order[j]] - x[order[i]]);
      dp[j + 1] = min(dp[j + 1], dp[i] + sum);
    }
  }                                       
  cout << dp[n] << '\n';
  return 0;
}