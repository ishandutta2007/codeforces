#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int MOD = (119 << 23) + 1;

vector<bool> ok[N];
vector<int> dp[N];
string grid[N];

int add(int a, int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
    dp[i].resize(m);
    ok[i].resize(m);
  }

  ok[n - 1][m - 1] = true;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (grid[i][j] != '#' && ((i + 1 < n && ok[i + 1][j]) || (j + 1 < m && ok[i][j + 1]))) {
        ok[i][j] = true;
      }
    }
  }

  auto check = [&](int i, int j) {
    return (i < n && j < m && ok[i][j]);
  };

  int ans = 2;
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dp[i][j] > 0) {
        int cnt = check(i + 1, j) + check(i, j + 1);
        int trans = (cnt == 1) ? dp[i][j] : mul(dp[i][j], (MOD + 1) / 2);
        if (check(i + 1, j)) {
          dp[i + 1][j] = add(dp[i + 1][j], trans);
        }
        if (check(i, j + 1)) {
          dp[i][j + 1] = add(dp[i][j + 1], trans);
        }
      }
      if ((i | j) != 0 && (i < n - 1 || j < m - 1) && dp[i][j] == 1) {
        ans = 1;
      }
    }
  }

  if (dp[n - 1][m - 1] == 0) {
    ans = 0;
  }

  cout << ans << "\n";
}