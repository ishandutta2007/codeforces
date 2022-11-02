#include <bits/stdc++.h>

const int N = 200000;

int a[N + 5], b[N + 5], n;
bool check(int x) {
  int nw = 1;
  for (int i = 1; i <= n; i++)
    if (b[i] >= nw - 1 && a[i] >= x - nw) nw++;
  return nw > x;
}
void solve() {
  scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);

  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  printf("%d\n", l);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
}