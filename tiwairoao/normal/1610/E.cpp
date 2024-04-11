#include <bits/stdc++.h>

const int N = 200000;

int a[N + 5], n;

void solve() {
  scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int ans = 2;
  for (int i = 1, j; i <= n; i = j) {
    for (j = i; j <= n && a[i] == a[j]; j++) continue;

    int res = j - i, nw = j;
    while (nw <= n) {
      res++;
      nw = std::lower_bound(a + 1, a + n + 1, 2 * a[nw] - a[i]) - a;
    }
    ans = std::max(ans, res);
  }

  printf("%d\n", n - ans);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
}