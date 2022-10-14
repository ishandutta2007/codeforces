#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  if (n > 3 && m > 3) {
    cout << -1 << '\n';
    return 0;
  }
  if (n > 3) {
    vector<string> t(m);
    for (int i = 0; i < m; i++) {
      t[i] = string(n, '1');
    }  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        t[j][i] = s[i][j];
      }
    }
    swap(n, m);
    s = t;
  }
  const int inf = 1e8;
  vector<vector<int>> dp(m, vector<int>(1 << n, inf));
  for (int p = 0; p < (1 << n); p++) {
    int ft = 0;
    for (int i = 0; i < n; i++) {
      int bit = p >> i & 1;
      if (s[i][0] != (char) ('0' + bit)) {
        ft += 1;
      }
    }
    dp[0][p] = ft;
  }
  vector<vector<bool>> can(1 << n, vector<bool>(1 << n, true));
  for (int p = 0; p < (1 << n); p++) {
    for (int q = 0; q < (1 << n); q++) {
      for (int i = 0; i + 1 < n; i++) {
        int cc = 0;
        if (p >> i & 1) cc += 1;
        if (q >> i & 1) cc += 1;
        if (p >> (i + 1) & 1) cc += 1;
        if (q >> (i + 1) & 1) cc += 1;
        if (cc % 2 == 0) {                 
          can[p][q] = false;
        }
      }
    }
  }
  for (int i = 1; i < m; i++) {       
    for (int p = 0; p < (1 << n); p++) {
      int ft = 0;
      for (int j = 0; j < n; j++) {
        int bit = p >> j & 1;
        if (s[j][i] != (char) ('0' + bit)) {
          ft += 1;
        }
      }
      for (int q = 0; q < (1 << n); q++) {
        if (can[p][q]) {
          dp[i][p] = min(dp[i][p], dp[i - 1][q] + ft);  
        }
      }
    }
  }
  int ans = inf;
  for (int p = 0; p < (1 << n); p++) {
    ans = min(ans, dp[m - 1][p]);
  }                          
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}