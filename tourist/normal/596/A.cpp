#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set <int> xs;
  set <int> ys;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    xs.insert(a);
    ys.insert(b);
  }
  assert(xs.size() <= 2 && ys.size() <= 2);
  if (xs.size() == 2 && ys.size() == 2) {
    int a = *(xs.begin());
    int b = *(++xs.begin());
    int c = *(ys.begin());
    int d = *(++ys.begin());
    printf("%d\n", (b - a) * (d - c));
  } else {
    puts("-1");
  }
  return 0;
}