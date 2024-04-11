#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int main() {
  int n;
  scanf("%d", &n);
  int from = -inf, to = inf;
  int delta = 0;
  for (int i = 0; i < n; i++) {
    int d, cur;
    scanf("%d %d", &cur, &d);
    if (d == 1) {
      from = max(from, 1900 - delta);
    } else {
      to = min(to, 1899 - delta);
    }
    delta += cur;
  }
  if (from > to) {
    puts("Impossible");
    return 0;
  }
  if (to == inf) {
    puts("Infinity");
    return 0;
  }
  printf("%d\n", to + delta);
  return 0;
}