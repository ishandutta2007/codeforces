#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  d.push_back(l);
  a.push_back(69);
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      for (int q = 0; q <= k; q++) {
        int old_q = q - (i - j - 1);
        if (old_q < 0) {
          continue;
        }
        dp[i][q] = min(dp[i][q], dp[j][old_q] + a[j] * (d[i] - d[j]));
      }
    }
  }
  cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
  return 0;
}