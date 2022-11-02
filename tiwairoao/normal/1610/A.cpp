#include <bits/stdc++.h>

int main() {
  int t, n, m; scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) puts("0");
    else if (n == 1 || m == 1) puts("1");
    else puts("2");
  }
}