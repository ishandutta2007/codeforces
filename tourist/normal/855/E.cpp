/**
 *    author:  tourist
 *    created: 24.09.2017 17:40:31       
**/
#include <bits/stdc++.h>

using namespace std;

long long dp[13][77][1234];

long long solve(int b, long long n) {
  vector<int> d;
  while (n > 0) {
    d.push_back(n % b);
    n /= b;
  }
  int len = d.size();
  long long res = 0;
  for (int small_len = 1; small_len < len; small_len++) {
    res += dp[b][small_len][0] - dp[b][small_len - 1][1];
  }
  int mask = 0;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 0; j < d[i]; j++) {
      if (i == len - 1 && j == 0) {
        continue;
      }
      res += dp[b][i][mask ^ (1 << j)];
    }
    mask ^= (1 << d[i]);
  }
  return res;
}

int main() {
  for (int b = 2; b <= 10; b++) {
    dp[b][0][0] = 1;
    for (int i = 1; i <= 63; i++) {
      for (int t = 0; t < (1 << b); t++) {
        dp[b][i][t] = 0;
        for (int d = 0; d < b; d++) {
          dp[b][i][t] += dp[b][i - 1][t ^ (1 << d)];
        }
      }
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int b;
    long long from, to;
    scanf("%d %I64d %I64d", &b, &from, &to);
    printf("%I64d\n", solve(b, to + 1) - solve(b, from));
  }
  return 0;
}