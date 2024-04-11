#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int k2 = 0, k3 = 0, k6 = 0;
  for (int i = 1; ; i++) {
    if (i % 6 == 0) {
      k6++;
    } else {
      if (i % 2 == 0) {
        k2++;
      }
      if (i % 3 == 0) {
        k3++;
      }
    }
    k2 = min(k2, n);
    k3 = min(k3, m);
    int need = (n - k2) + (m - k3);
    if (need <= k6) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}