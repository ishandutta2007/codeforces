#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 2) {
    if (n >= 5) {
      printf("%d\n", n - 1);
      for (int i = 1; i < n; i++) {
        printf("%d %d\n", i, i + 1);
      }
      return 0;
    }
  }
  if (k == 3) {
    if (n >= 4) {
      printf("%d\n", (n - 2) * (n - 3) / 2 + 2);
      for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
          printf("%d %d\n", i, j);
        }
      }
      printf("%d %d\n", n - 2, n - 1);
      printf("%d %d\n", n - 1, n);
      return 0;
    }
  }
  printf("%d\n", -1);
  return 0;
}