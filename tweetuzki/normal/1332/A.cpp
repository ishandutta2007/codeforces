#include <algorithm>
#include <cstdio>
#include <cstring>
 
int main() {
  int Te;
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    int a, b, c, d;
    int x, y, xl, yl, xr, yr;
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &x, &y, &xl, &yl, &xr, &yr);
    if (xl == xr && a + b > 0) {
      puts("No");
      continue;
    }
    if (yl == yr && c + d > 0) {
      puts("No");
      continue;
    }
    if (a > b && x - a + b < xl) {
      puts("No");
      continue;
    }
    if (a < b && x - a + b > xr) {
      puts("No");
      continue;
    }
    if (c > d && y - c + d < yl) {
      puts("No");
      continue;
    }
    if (c < d && y - c + d > yr) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}