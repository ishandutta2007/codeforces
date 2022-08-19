#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

double p[5 * N];
double z[5 * N];
int a[5 * N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  double prob = 1.0 / (n * (n - 1) / 2);
  for (int diff = 1; diff < N; diff++) {
    p[diff] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      p[a[j] - a[i]] += prob;
    }
  }
  for (int d = 1; d < 2 * N; d++) {
    z[d] = 0.0;
  }
  for (int d = 1; d < N; d++) {
    for (int u = 1; u < N; u++) {
      z[d + u] += p[d] * p[u];
    }
  }
  double ans = 0.0;
  double total = 0.0;
  for (int d = 1; d < N; d++) {
    ans += p[d] * total;
    total += z[d];
  }
  printf("%.17f\n", ans);
  return 0;
}