#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 2e18;

long long f[23456789];

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  f[1] = x;
  int up = 1;
  while (up < n) {
    for (int i = up + 1; i <= 2 * up; i++) {
      if (i & 1) {
        f[i] = inf;
      } else {
        f[i] = f[i / 2] + y;
      }
    }
    for (int i = up; i < 2 * up; i++) {
      f[i + 1] = min(f[i + 1], f[i] + x);
    }
    for (int i = 2 * up; i > up; i--) {
      f[i - 1] = min(f[i - 1], f[i] + x);
    }
    up *= 2;
  }
  printf("%I64d\n", f[n]);
  return 0;
}