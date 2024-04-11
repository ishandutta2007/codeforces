#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if (n > a * b) {
    puts("-1");
    return 0;
  }
  int c[2];
  c[0] = 1;
  c[1] = 2;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (j > 0) {
        putchar(' ');
      }
      int p = (i + j) % 2;
      printf("%d", c[p] <= n ? c[p] : 0);
      c[p] += 2;
    }
    printf("\n");
  }
  return 0;
}