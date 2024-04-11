#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

void add(int& x, int y) {
  x += y;
  if (x >= mod) x %= mod;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, d;
  cin >> m >> d;
  string a, b;
  cin >> a >> b;
  int len = (int) b.size();
  vector<int> pw(len);
  pw[0] = 1;
  for (int i = 1; i < len; i++) {
    pw[i] = pw[i - 1] * 10;
    pw[i] %= m;
  }
  auto Solve = [&](string s) {
    int n = (int) s.size();
    const int inf = 1e8;
    vector<vector<int>> dp(m + 1, vector<int>(2, 0));
    int fir_dig = s[0] - '0';
    for (int i = 0; i <= fir_dig; i++) {
      if (i == d) continue;
      dp[(i * pw[n - 1]) % m][(i == fir_dig) ? 1 : 0] += 1;
    }
    for (int i = 1; i < n; i++) {
      vector<vector<int>> new_dp(m, vector<int>(2, 0));
      for (int j = 0; j < 10; j++) {
        if (i % 2 == 1 && j != d) continue;
        if (i % 2 == 0 && j == d) continue;
        int dig = s[i] - '0';
        for (int l = 0; l < m; l++) {
          add(new_dp[(l + pw[n - i - 1] * j) % m][0], dp[l][0]);
        }
        if (j == dig) {
          for (int l = 0; l < m; l++) {
            add(new_dp[(l + pw[n - i - 1] * j) % m][1], dp[l][1]);
          }
        } else {
          if (j > dig) continue;
          for (int l = 0; l < m; l++) {
            add(new_dp[(l + pw[n - i - 1] * j) % m][0], dp[l][1]);
          }
        }
      }
      swap(new_dp, dp);
    }
    int ans = 0;
    add(ans, dp[0][0]);
    add(ans, dp[0][1]);
    return ans;
  };
  auto Ok = [&](string s) {
    int n = (int) s.size();
    for (int i = 0; i < n; i++) if (i % 2 == 1 && (int) (s[i] - '0') != d) return false;
    for (int i = 0; i < n; i++) if (i % 2 == 0 && (int) (s[i] - '0') == d) return false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += pw[n - i - 1] * (int) (s[i] - '0');
      sum %= m;
    }
    return sum == 0;
  };
  cout << (Solve(b) - Solve(a) + Ok(a) + mod) % mod << '\n';
  return 0;
}