//14E
#include<cstdio>

int n, t, f[21][4][21], ans;

int main() {
  scanf("%d %d", &n, &t);
  f[0][0][0] = 1;
  f[0][1][0] = 1;
  f[0][2][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 2 * t; k++) {
        for (int l = 0; l < 4; l++) {
          if (i == 1 && j > l || i > 1 && j != l) {
            f[i][j][k + (j < l != k % 2)] += f[i - 1][l][k];
          }
        }
      }
    }
  }
  ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += f[n - 1][i][t * 2 - 1];
  }
  printf("%d\n", ans);
  return 0;
}