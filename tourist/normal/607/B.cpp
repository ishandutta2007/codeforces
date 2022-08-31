#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e9;
const int N = 777;

int c[N];
int f[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        f[i][j] = 1;
        continue;
      }
      if (i + 1 == j) {
        f[i][j] = (c[i] == c[j] ? 1 : 2);
        continue;
      }
      f[i][j] = inf;
      for (int k = i; k < j; k++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
      }
      if (c[i] == c[j]) {
        f[i][j] = min(f[i][j], f[i + 1][j - 1]);
      }
    }
  }
  printf("%d\n", f[0][n - 1]);
  return 0;
}