/**
 *    author:  tourist
 *    created: 30.07.2019 18:10:20       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int dp[N][N][N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f[i + 1][j + 1] = f[i + 1][j] + f[i][j + 1] - f[i][j] + (s[i][j] == '#');
    }
  }
  auto Get = [&](int xa, int ya, int xb, int yb) {
    return f[xb + 1][yb + 1] - f[xa][yb + 1] - f[xb + 1][ya] + f[xa][ya];
  };
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      for (int ii = i; ii < n; ii++) {
        for (int jj = j; jj < n; jj++) {
          if (Get(i, j, ii, jj) == 0) {
            dp[i][j][ii][jj] = 0;
            continue;
          }
          int res = max(ii - i + 1, jj - j + 1);
          for (int k = i; k < ii; k++) {
            res = min(res, dp[i][j][k][jj] + dp[k + 1][j][ii][jj]);
          }
          for (int k = j; k < jj; k++) {
            res = min(res, dp[i][j][ii][k] + dp[i][k + 1][ii][jj]);
          }
          dp[i][j][ii][jj] = res;
        }
      }
    }
  }
  cout << dp[0][0][n - 1][n - 1] << '\n';
  return 0;
}