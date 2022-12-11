#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif

  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a, b, c, d;
    scanf("%d%d", &c, &d);
    a = b = 0;
    int d1 = abs(b - a) % 2;
    int d2 = abs(d - c) % 2;
    if (d1 != d2) {
      puts("-1");
    } else {
      if (a == c && b == d) {
        puts("0");
      } else if (b - a == d - c) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }

  return 0;
}