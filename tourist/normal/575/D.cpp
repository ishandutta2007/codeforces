#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1000;
  printf("%d\n", 2 * n);
  for (int i = 1; i <= n; i++) {
    printf("%d %d %d %d\n", i, 1, i, 2);
  }
  for (int i = n; i >= 1; i--) {
    printf("%d %d %d %d\n", i, 1, i, 2);
  }
  return 0;
}