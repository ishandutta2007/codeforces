/**
 *    author:  tourist
 *    created: 30.12.2020 17:38:39       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> dp(4, (int) 1e9);
    dp[0] = 0;
    for (int it = 0; it < n; it++) {
      vector<int> new_dp(4, (int) 1e9);
      for (int mask = 0; mask < 4; mask++) {
        for (int take = 0; take < 2; take++) {
          int b1 = (mask >> 1) & 1;
          int b0 = mask & 1;
          int new_mask = (b0 << 1) | take;
          if (take == 0) {
            new_dp[new_mask] = min(new_dp[new_mask], dp[mask] + 1);
          } else {
            if (b0 == 1 && it > 0 && s[it - 1] == s[it]) {
              continue;
            }
            if (b1 == 1 && it > 1 && s[it - 2] == s[it]) {
              continue;
            }
            new_dp[new_mask] = min(new_dp[new_mask], dp[mask]);
          }
        }
      }
      swap(dp, new_dp);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}