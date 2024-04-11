#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 2000000000;

int n, a[305][305], f[605][305][305];

inline int max(const int &a, const int &b) {return a < b ? b : a;}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  if (n == 1) {
    printf("%d\n", a[1][1]);
    return 0;
  }
  for (int i = 0; i <= n * 2; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n; ++k) {
        f[i][j][k] = -INF;
      }
    }
  }
  f[2][1][0] = a[1][1] + a[1][2] + a[2][1];
  f[2][1][1] = a[1][1] + a[2][1];
  f[2][0][0] = a[1][1] + a[1][2];
  for (int i = 3; i <= n * 2 - 1; ++i) {
    for (int j = 0; j <= n && j < i; ++j) {
      for (int k = 0; k <= j; ++k) {
        if (j > 0 && k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1]);
        f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
        if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1]);
        if (j > k) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k]);
        if (j != k) f[i][j][k] += a[j + 1][i - j] + a[k + 1][i - k]; else f[i][j][k] += a[j + 1][i - j];
        //printf("%d %d %d : %d\n", i, j, k, f[i][j][k]);
      }
    }
  }
  printf("%d\n", f[n * 2 - 1][n - 1][n - 1]);
  return 0;
}