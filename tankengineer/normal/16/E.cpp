//16E
#include<cstdio>
#include<cmath>

int n, cnt;
double g[18][18], f[524288];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < n; j++) {
      scanf("%lf", &g[i][j]);
    }
  }
  f[(1 << n) - 1] = 1;
  for (int i = (1 << n) - 1; i > 0; i--) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        cnt++;
      }
    }
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) continue; 
      for (int k = j + 1; k < n; k++) {
        if ((i & (1 << k)) == 0) continue;
        f[i - (1 << k)] += f[i] * g[j][k] * 2 / cnt / (cnt - 1);
        f[i - (1 << j)] += f[i] * g[k][j] * 2 / cnt / (cnt - 1);
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%.12lf ", f[(1 << i)]);
  }
  printf("%.12lf\n", f[1 << (n - 1)]);
  return 0;
}