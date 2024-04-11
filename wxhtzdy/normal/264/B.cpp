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
  const int MAX = 1e5 + 5;
  vector<int> dp(MAX);
  for (int i = n - 1; i >= 0; i--) {
    dp[a[i]] += 1;
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        dp[a[i]] = max(dp[a[i]], dp[j] + 1);
        dp[a[i]] = max(dp[a[i]], dp[a[i] / j] + 1);
      }
    }
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        dp[j] = max(dp[j], dp[a[i]]);
        dp[a[i] / j] = max(dp[a[i] / j], dp[a[i]]);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}