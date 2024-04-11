#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

int mul(int a, int b) {
  return a * 1LL * b % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  a.push_back(100000);
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> new_dp(n + 1, vector<int>(k + 1));
    for (int j = 0; j < n; j++) {
      for (int s = 0; s <= k; s++) {
        // open one group
        {
          int t = s + (j + 1) * (a[i + 1] - a[i]);
          if (t <= k) {
            add(new_dp[j + 1][t], dp[j][s]);
          }
        }
        // same
        {
          int t = s + j * (a[i + 1] - a[i]);
          if (t <= k) {
            add(new_dp[j][t], mul(dp[j][s], j + 1));
          }
        }
        // close one group
        if (j > 0) {
          int t = s + (j - 1) * (a[i + 1] - a[i]);
          if (t <= k) {
            add(new_dp[j - 1][t], mul(dp[j][s], j));
          }
        }
      }
    }
    swap(dp, new_dp);
  }
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    add(ans, dp[0][i]);
  }
  cout << ans << '\n';
  return 0;
}