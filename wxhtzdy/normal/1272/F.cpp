#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  const int M = 205;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(M, 1e9)));
  vector<vector<vector<tuple<int, int, int, char>>>> take(n + 1, vector<vector<tuple<int, int, int, char>>>(m + 1, vector<tuple<int, int, int, char>>(M)));
  dp[0][0][0] = 0;
  for (int x = 0; x <= n; x++) {
    for (int y = 0; y <= m; y++) {
      for (int bal = 0; bal < M - 2; bal++) {
        {
          int nx = x + (x != n && s[x] == '(');
          int ny = y + (y != m && t[y] == '(');
          if (dp[nx][ny][bal + 1] > dp[x][y][bal] + 1) {
            dp[nx][ny][bal + 1] = dp[x][y][bal] + 1;
            take[nx][ny][bal + 1] = {x, y, bal, '('};
          }
        }
        if (bal > 0) {
          int nx = x + (x != n && s[x] == ')');
          int ny = y + (y != m && t[y] == ')');
          if (dp[nx][ny][bal - 1] > dp[x][y][bal] + 1) {
            dp[nx][ny][bal - 1] = dp[x][y][bal] + 1;
            take[nx][ny][bal - 1] = {x, y, bal, ')'};
          }
        }
      }
    }
  }
  int st_bal = 0;
  for (int i = 0; i < M; i++) {
    if (dp[n][m][st_bal] + st_bal > dp[n][m][i] + i) {
      st_bal = i;
    }
  }
  //cout << dp[n][m][st_bal] << '\n';
  string ans = "";
  for (int rep = 0; rep < st_bal; rep++) {
    ans += ')';
  }
  function<void(int, int, int)> Dfs = [&](int i, int j, int bal) {
    if (i == 0 && j == 0 && bal == 0) {
      return;
    }
    //cout << i << " " << j << " " << bal << endl;
    ans += get<3>(take[i][j][bal]);
    Dfs(get<0>(take[i][j][bal]), get<1>(take[i][j][bal]), get<2>(take[i][j][bal]));
  };
  Dfs(n, m, st_bal);
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}