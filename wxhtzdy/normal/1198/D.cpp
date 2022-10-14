#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (s[i][j] == '#' ? 1 : 0);
    }
  }                                                   
  auto Get = [&](int xa, int ya, int xb, int yb) {
    return pref[xb + 1][yb + 1] - pref[xb + 1][ya] - pref[xa][yb + 1] + pref[xa][ya];
  };
  vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n))));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      for (int ii = i; ii < n; ii++) {
        for (int jj = j; jj < n; jj++) {
          if (Get(i, j, ii, jj) == 0) {
            continue;
          }
          int ft = max(ii - i + 1, jj - j + 1);
          for (int p = i; p < ii; p++) {
            ft = min(ft, dp[i][j][p][jj] + dp[p + 1][j][ii][jj]);
          }
          for (int p = j; p < jj; p++) {
            ft = min(ft, dp[i][j][ii][p] + dp[i][p + 1][ii][jj]);
          }
          dp[i][j][ii][jj] = ft;
        }
      }
    }
  }
  cout << dp[0][0][n - 1][n - 1] << '\n';
  return 0;
}