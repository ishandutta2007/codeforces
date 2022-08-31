/**
 *    author:  tourist
 *    created: 16.09.2017 20:43:48       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 777;

int a[N][N];
double f[N][N], p[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    p[0][i] = 1.0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      double cur = 0.0;
      for (int k = 0; k < (1 << n); k++) {
        int meet = j ^ k;
        int bits = 0;
        while (meet > 0) {
          bits++;
          meet /= 2;
        }
        if (bits == i) {
          cur += a[j][k] * 0.01 * p[i - 1][k];
        }
      }
      cur *= p[i - 1][j];
      p[i][j] = cur;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    f[0][i] = 0.0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      f[i][j] = 0.0;
      for (int k = 0; k < (1 << n); k++) {
        int meet = j ^ k;
        int bits = 0;
        while (meet > 0) {
          bits++;
          meet /= 2;
        }
        if (bits == i) {
          f[i][j] = max(f[i][j], f[i - 1][k]);
        }
      }
      f[i][j] += f[i - 1][j];
      f[i][j] += (1 << (i - 1)) * p[i][j];
    }
  }
  double ans = 0.0;
  for (int j = 0; j < (1 << n); j++) {
    ans = max(ans, f[n][j]);
  }
  printf("%.17f\n", ans);
  return 0;
}