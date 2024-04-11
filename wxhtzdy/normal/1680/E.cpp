#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> g(2);
    cin >> g[0] >> g[1];
    int L = 0;
    while (g[0][L] != '*' && g[1][L] != '*') {
      L += 1;
    }
    int R = n - 1;
    while (g[0][R] != '*' && g[1][R] != '*') {
      R -= 1;
    }
    const int inf = 1e9;
    vector<int> dp(4, inf);
    dp[0] = 0;
    for (int i = L; i <= R; i++) {
      vector<int> ndp(4, inf);
      int cc = 0;
      for (int j = 0; j < 2; j++) {
        if (g[j][i] == '*') {
          cc += 1;
        }
      }
      for (int s = 1; s < 4; s++) {
        for (int t = 0; t < 4; t++) {
          int ft = __builtin_popcount(t);
          int st = 0;
          for (int j = 0; j < 2; j++) {
            if ((t >> j & 1) || g[j][i] == '*') {
              st |= (1 << j);
            }
          }
          if (__builtin_popcount(st) < ft) {
            continue;
          }
          ft += (st != s);
          ndp[s] = min(ndp[s], ft + dp[t]);
        }
      }
      swap(dp, ndp);
    }
    cout << min(dp[1], dp[2]) << '\n';
  }
  return 0;
}