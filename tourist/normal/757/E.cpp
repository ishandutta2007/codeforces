#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

const int N = 1010101;
const int ALPHA = 21;

int f[N][ALPHA];
int p[N];
int a[N];
int dp[777][777];

int main() {
  for (int j = 0; j < ALPHA; j++) {
    f[0][j] = (j == 0);
  }
  for (int i = 1; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < ALPHA; j++) {
      add(sum, f[i - 1][j]);
      f[i][j] = sum;
    }
  }
  for (int i = 1; i < N; i++) {
    p[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (p[i] == i) {
      for (int j = i + i; j < N; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int r, n;
    scanf("%d %d", &r, &n);
    int cnt = 0;
    int tmp = n;
    while (tmp > 1) {
      int d = p[tmp];
      a[cnt] = 0;
      while (tmp % d == 0) {
        a[cnt]++;
        tmp /= d;
      }
      cnt++;
    }
    for (int i = 0; i <= cnt; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < cnt; i++) {
      for (int j = 0; j <= i; j++) {
        add(dp[i + 1][j], mul(dp[i][j], f[r][a[i]]));
        add(dp[i + 1][j + 1], mul(dp[i][j], f[r + 1][a[i] - 1]));
      }
    }
    int ans = 0;
    for (int j = cnt; j >= 0; j--) {
      add(ans, ans);
      add(ans, dp[cnt][j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}