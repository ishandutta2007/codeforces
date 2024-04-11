#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

int cnt[10], l, s[105];
long long ans, f[12][105], c[105][105];

long long solve(int n) {
  memset(f, 0, sizeof(f));
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= 10; ++i) s[i] = s[i - 1] + cnt[i - 1];
  f[0][0] = 1;
  for (int i = 1; i <= 10; ++i) {
    for (int j = s[i]; j <= n; ++j) {
      for (int k = s[i - 1]; k <= j - cnt[i - 1]; ++k) {
        f[i][j] += (f[i - 1][k] * c[n - k][j - k]) % MOD;
        f[i][j] %= MOD;
      }
    }
  }
  return f[10][n];
}

int main() {
  c[0][0] = 1;
  c[1][1] = 1;
  c[1][0] = 1;
  for (int i = 1; i <= 100; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      c[i][j] %= MOD;
    }
  } 
  scanf("%d", &l);
  for (int i = 0; i <= 9; ++i) scanf("%d", &cnt[i]);
  ans = 0;
  for (int n = l; n >= 1; --n) {
    for (int i = 1; i <= 9; ++i) {
      int t1 = cnt[i];
      if (cnt[i]) --cnt[i];
      ans += solve(n - 1);
      ans %= MOD;
      cnt[i] = t1;
    }
    //printf("%I64d\n", ans);
  }
  printf("%I64d\n", ans);
  return 0;
}