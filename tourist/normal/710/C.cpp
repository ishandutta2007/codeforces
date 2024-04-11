#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int a[N][N], b[N][N];

int main() {
  int n;
  scanf("%d", &n);
  a[0][0] = 1;
  int k = 1;
  while (k < n) {
    memset(b, 255, sizeof(b));
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        b[i + 1][j + 1] = a[i][j];
      }
    }
    int ptr = k * k;
    for (int i = 1; i <= k; i++) {
      b[i][0] = (ptr += 2);
      b[i][k + 1] = (ptr += 2);
    }
    b[0][k / 2 + 1] = (ptr += 2);
    b[k + 1][k / 2 + 1] = (ptr += 2);
    ptr = k * k - 1;
    k += 2;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        a[i][j] = b[i][j];
        if (a[i][j] == -1) {
          a[i][j] = (ptr += 2);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        putchar(' ');
      }
      printf("%d", a[i][j]);
    }
    puts("");
  }
  return 0;
}