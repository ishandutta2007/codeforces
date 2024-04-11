//13D
#include<cstdio>

int n, m;
long long x1[500], x2[500], y1[500], y2[500], a, b, c, cnt[500][500], ans;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d %I64d", &x1[i], &y1[i]);
  for (int i = 0; i < m; i++) scanf("%I64d %I64d", &x2[i], &y2[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x1[i] < x1[j]) {
        a = y1[j] - y1[i];
        b = x1[i] - x1[j];
        c = -x1[i] * a - y1[i] * b;
        for (int k = 0; k < m; k++) {
          cnt[i][j] += (x2[k] > x1[i] && x2[k] <= x1[j] && a * x2[k] + b * y2[k] + c > 0);
        }
        cnt[j][i] = -cnt[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        ans += (cnt[i][j] + cnt[j][k] + cnt[k][i]) == 0;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}