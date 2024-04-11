#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

void test(int xa, int ya, int xb, int yb) {
  if (xa == xb || ya == yb || xb == 0 || yb == 0) {
    return;
  }
  puts("YES");
  printf("%d %d\n", 0, 0);
  printf("%d %d\n", xa, ya);
  printf("%d %d\n", xb, yb);
  exit(0);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int x = 1; x <= a; x++)
    for (int y = 1; y <= a; y++)
      if (x * x + y * y == a * a) {
        int g = gcd(x, y);
        int dx = x / g, dy = y / g;
        int u = dx * dx + dy * dy;
        int v = b * b;
        if (v % u != 0) {
          continue;
        }
        if (v % u == 0) {
          int ratio = v / u;
          int k = (int)sqrt(1.0 * ratio);
          while (k * k < ratio) k++;
          while (k * k > ratio) k--;
          if (k * k == ratio) {
            test(x, y, -dy * k, dx * k);
            test(x, y, dy * k, -dx * k);
          }
        }
      }
  puts("NO");
  return 0;
}