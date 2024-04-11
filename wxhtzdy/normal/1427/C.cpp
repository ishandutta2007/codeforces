#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> t(k), x(k), y(k);
  for (int i = 0; i < k; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  vector<int> dp(k, 0);
  int pref = 0;
  for (int i = 0; i < k; i++) {
    if (x[i] + y[i] - 2 > t[i]) {
      dp[i] = 0;
      continue;
    }
    int s = max(0, i - 4 * n);
    dp[i] = pref + 1;
    for (int j = i - 1; j >= s; j--) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= abs(t[i] - t[j])) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}