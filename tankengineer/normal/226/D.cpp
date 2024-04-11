#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, a[105][105], sumr[105], sumc[105], r[105], c[105];

void row() {
  for (int i = 1; i <= n; ++i) {
    if (sumr[i] < 0) {
      r[i] = 1 - r[i];
      for (int j = 1; j <= m; ++j) {
        sumr[i] -= a[i][j] * 2;
        sumc[j] -= a[i][j] * 2;
        a[i][j] = -a[i][j];
      }
    }
  }
}

void col() {
  for (int i = 1; i <= m; ++i) {
    if (sumc[i] < 0) {
      c[i] = 1 - c[i];
      for (int j = 1; j <= n; ++j) {
        sumr[j] -= a[j][i] * 2;
        sumc[i] -= a[j][i] * 2;
        a[j][i] = -a[j][i];
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      sumr[i] += a[i][j];
      sumc[j] += a[i][j];
    }
  }
  for (int i = 1; i <= 100; ++i) {
    row();
    col();
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += r[i];
  }
  printf("%d", cnt);
  for (int i = 1; i <= n; ++i) {
    if (r[i]) printf(" %d", i);
  }
  printf("\n");
  cnt = 0;
  for (int i = 1; i <= m; ++i) {
    cnt += c[i];
  }
  printf("%d", cnt);
  for (int i = 1; i <= m; ++i) {
    if (c[i]) printf(" %d", i);
  }
  printf("\n");
  return 0;
}