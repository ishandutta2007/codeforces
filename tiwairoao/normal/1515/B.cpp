#include <bits/stdc++.h>

bool sqr(int x) {
  int s = (int)sqrt(x);
  return s * s == x;
}

int main() {
  int t, n; scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (!(n & 1) && sqr(n >> 1)) puts("YES");
    else if (!(n & 3) && sqr(n >> 2)) puts("YES");
    else puts("NO");
  }
}