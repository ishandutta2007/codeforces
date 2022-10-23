/**
 *    author:  tourist
 *    created: 30.09.2022 17:39:53       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x & 1] += 1;
    }
    vector<vector<vector<int>>> dp(cnt[0] + 1, vector<vector<int>>(cnt[1] + 1, vector<int>(2)));
    for (int i0 = 0; i0 <= cnt[0]; i0++) {
      for (int i1 = 0; i1 <= cnt[1]; i1++) {
        for (int p = 0; p < 2; p++) {
          if (i0 == 0 && i1 == 0) {
            dp[i0][i1][p] = (p == 0 ? 1 : 0);
            continue;
          }
          if ((i0 + i1) % 2 == (cnt[0] + cnt[1]) % 2) {
            dp[i0][i1][p] = 0;
            if (i0 > 0) {
              if (dp[i0 - 1][i1][p]) {
                dp[i0][i1][p] = 1;
              }
            }
            if (i1 > 0) {
              if (dp[i0][i1 - 1][p ^ 1]) {
                dp[i0][i1][p] = 1;
              }
            }
          } else {
            dp[i0][i1][p] = 1;
            if (i0 > 0) {
              if (!dp[i0 - 1][i1][p]) {
                dp[i0][i1][p] = 0;
              }
            }
            if (i1 > 0) {
              if (!dp[i0][i1 - 1][p]) {
                dp[i0][i1][p] = 0;
              }
            }
          }
        }
      }
    }
    cout << (dp[cnt[0]][cnt[1]][0] ? "Alice" : "Bob") << '\n';
  }
  return 0;
}