#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  int d, e; scanf("%d%d", &d, &e);
  int a = d, b = 5 * e;
  int ans = n;
  for (int i = 0; i * a <= n; ++i) {
    ans = min(ans, (n - a * i) % b);
  }
  printf("%d\n", ans);
}