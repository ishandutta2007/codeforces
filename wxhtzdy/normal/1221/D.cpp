/**
 *  author: milos
 *  created: 02.01.2021 00:49:30
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
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    const long long inf = 1e18;                  
    vector<vector<long long>> dp(n, vector<long long>(5, inf));
    for (int i = 0; i < 4; i++) {
      dp[0][i] = b[0] * i;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        long long bonus = j * b[i];
        for (int k = 0; k < 4; k++) {
          int x = a[i] + j, y = a[i - 1] + k;
          if (x != y) {
            if (dp[i - 1][k] != inf) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + bonus);
            }
          }
        }
      }
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
  }
  return 0;
}