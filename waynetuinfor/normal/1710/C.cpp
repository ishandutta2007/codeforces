#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  constexpr int kP = 998244353;
  int N = s.size();
  // a ^ b + b ^ c < a ^ c
  // dp[i][a < n][b < n][c < n][a ^ b + b ^ c < a ^ c][carry]
  vector dp(2, vector(2, vector(2, vector(2, vector<int>(2)))));
  dp[0][0][0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    vector nxt(2, vector(2, vector(2, vector(2, vector<int>(2)))));
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        for (int c = 0; c < 2; ++c) {
          for (int d = 0; d < 2; ++d) {
            for (int carry = 0; carry < 2; ++carry) {
              if (dp[a][b][c][d][carry] == 0) {
                continue;
              }
              int cur = s[i] - '0';
              for (int ai = 0; ai < 2; ++ai) {
                if (!a && ai > cur) {
                  continue;
                }
                for (int bi = 0; bi < 2; ++bi) {
                  if (!b && bi > cur) {
                    continue;
                  }
                  for (int ci = 0; ci < 2; ++ci) {
                    if (!c && ci > cur) {
                      continue;
                    }
                    int na = a || (ai < cur);
                    int nb = b || (bi < cur);
                    int nc = c || (ci < cur);
                    for (int has_carry = 0; has_carry < 2; ++has_carry) {
                      int s = (ai ^ bi) + (bi ^ ci) + has_carry;
                      if (s / 2 != carry) {
                        continue;
                      }
                      if (!d && s % 2 > (ai ^ ci)) {
                        continue;
                      }
                      int nd = d || (s % 2 < (ai ^ ci));
                      nxt[na][nb][nc][nd][has_carry] += dp[a][b][c][d][carry];
                      nxt[na][nb][nc][nd][has_carry] %= kP;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    dp = nxt;
  }
  int ans = 0;
  for (int a = 0; a < 2; ++a) {
    for (int b = 0; b < 2; ++b) {
      for (int c = 0; c < 2; ++c) {
        ans += dp[a][b][c][0][0];
        ans %= kP;
        ans += dp[a][b][c][1][0];
        ans %= kP;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    res = (2LL * res + (s[i] - '0')) % kP;
  }
  res++;
  (ans += kP - res) %= kP;
  (ans += kP - 1LL * res * (res + kP - 1) % kP) %= kP;
  (ans += kP - 1LL * res * (res + kP - 1) % kP) %= kP;
  int total = 1LL * res * (res + kP - 1) % kP * (res + kP - 2) % kP;
  cout << (total + kP - 3LL * ans % kP) % kP << "\n";
  return 0;
}