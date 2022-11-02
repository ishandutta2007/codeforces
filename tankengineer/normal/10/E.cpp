//CF 10E
#include<cstdio>

int n, c[405], ans, t1, t2, m, g;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  ans = -1;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      t1 = c[i - 1] - 1; m = 0;
      for (int k = i; k <= j; k++) {
        m += t1 / c[k];
        t1 = t1 % c[k];
      }
      t2 = t1 = c[i - 1] - 1 + c[j] - t1; g = 0;
      for (int k = 1; k <= n; k++) {
        g += t1 / c[k];
        t1 = t1 % c[k];
      }
      if (m + 1 < g && (ans == -1 || t2 < ans)) {
        ans = t2;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}