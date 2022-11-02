//CF 2B
#include<stdio.h>

int n, t, zerox, f[1005][1005][2], dp[1005][1005][2], ans, tx, ty, tk, l;
char bf[1005][1005][2], rut[2012];
bool zeroflag;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &t);
      if (!t) {
        zeroflag = true;
        zerox = i;
        continue;
      }
      while (t % 2 == 0) {
        f[i][j][0]++;
        t /= 2;
      }
      while (t % 5 == 0) {
        f[i][j][1]++;
        t /= 5;
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= 1; k++) {
        if (i != 1 || j != 1) {
          dp[i][j][k] = 100000000; 
        } else {
          dp[i][j][k] = f[i][j][k];
        }
        if (i > 1 && dp[i][j][k] > dp[i - 1][j][k] + f[i][j][k]) {
          dp[i][j][k] = dp[i - 1][j][k] + f[i][j][k];
          bf[i][j][k] = 'D';
        }
        if (j > 1 && dp[i][j][k] > dp[i][j - 1][k] + f[i][j][k]) {
          dp[i][j][k] = dp[i][j - 1][k] + f[i][j][k];
          bf[i][j][k] = 'R';
        }
      }
    }
  }
  l = 2 * n - 2; ans = dp[n][n][0] < dp[n][n][1] ? dp[n][n][0] : dp[n][n][1];
  if (zeroflag && ans > 1) {
    ans = 1;
    for (int i = n; i > zerox; i--) rut[--l] = 'D';
    for (int i = n; i > 1; i--) rut[--l] = 'R';
    for (int i = zerox; i > 1; i--) rut[--l] = 'D';
  } else {
    tx = n; ty = n; tk = dp[n][n][0] < dp[n][n][1] ? 0 : 1;
    while (bf[tx][ty][tk] != '\0') {
      rut[--l] = bf[tx][ty][tk];
      if (bf[tx][ty][tk] == 'D') {
        tx--;
      } else {
        ty--;
      }
    }
  }
  
  printf("%d\n%s\n", ans, rut);
}