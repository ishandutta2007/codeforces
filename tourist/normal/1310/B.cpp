/**
 *    author:  tourist
 *    created: 24.02.2020 16:16:46       
**/
#include <bits/stdc++.h>

using namespace std;

int dp[20][1 << 17][2][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> fan(1 << n);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    --x;
    fan[x] = 1;
  }
  memset(dp, 255, sizeof(dp));
  for (int i = 0; i < (1 << n); i += 2) {
    dp[1][i][fan[i]][fan[i + 1]] = (fan[i] | fan[i + 1]);
    dp[1][i][fan[i + 1]][fan[i]] = (fan[i] | fan[i + 1]);
  }
  for (int j = 2; j <= n; j++) {
    for (int i = 0; i < (1 << n); i += (1 << j)) {
      int k = i + (1 << (j - 1));
      for (int ui = 0; ui < 2; ui++) { 
        for (int li = 0; li < 2; li++) {
          for (int uk = 0; uk < 2; uk++) {
            for (int lk = 0; lk < 2; lk++) {
              int fi = dp[j - 1][i][ui][li];
              int fk = dp[j - 1][k][uk][lk];
              if (fi >= 0 && fk >= 0) {
                int ft = fi + fk + (ui | uk) + (li | lk);
                for (int uw = 0; uw < 2; uw++) {
                  for (int lw = 0; lw < 2; lw++) {
                    for (int lw2 = 0; lw2 < 2; lw2++) {
                      int new_u = (uw == 0 ? ui : uk);
                      int new_l = (lw == 0 ? li : lk);
                      int new_ft = ft + (new_l | (ui ^ uk ^ new_u));
                      int new_l2 = (lw2 == 0 ? new_l : (ui ^ uk ^ new_u));
                      dp[j][i][new_u][new_l2] = max(dp[j][i][new_u][new_l2], new_ft);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int ui = 0; ui < 2; ui++) { 
    for (int li = 0; li < 2; li++) {
      ans = max(ans, dp[n][0][ui][li] + (ui | li));
    }
  }
  cout << ans << '\n';
  return 0;
}