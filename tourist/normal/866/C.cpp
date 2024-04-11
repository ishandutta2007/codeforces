/**
 *    author:  tourist
 *    created: 30.09.2017 20:16:50       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int MAX = 12345;

int a[N], b[N], p[N], sum_b[N];
double f[N][MAX];

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", a + i, b + i, p + i);
  }
  sum_b[0] = 0;
  for (int i = 0; i < n; i++) {
    sum_b[i + 1] = sum_b[i] + b[i];
  }
  double low = 0.0, high = 1e15;
  for (int it = 0; it < 120; it++) {
    double mid = (low + high) * 0.5;
    for (int i = n; i >= 0; i--) {
      for (int j = 0; j <= sum_b[i]; j++) {
        if (i == n) {
          f[i][j] = (j <= r ? 0.0 : mid);
          continue;
        }
        f[i][j] = 0.01 * ((f[i + 1][j + a[i]] + a[i]) * p[i] + (f[i + 1][j + b[i]] + b[i]) * (100 - p[i]));
        if (i > 0) {
          f[i][j] = min(f[i][j], mid);
        }
      }
    }
    if (f[0][0] > mid) {
      low = mid;
    } else {
      high = mid;
    }
  }
  double ans = 0.5 * (low + high);
  printf("%.17f\n", ans);
  return 0;
}