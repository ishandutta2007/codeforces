#include <bits/stdc++.h>

const int N = 200000;

int a[N + 5], n;
bool del(int x) {
  static int b[N + 5]; int m = 0;
  for (int i = 1; i <= n; i++) if (a[i] != x) b[++m] = a[i];
  for (int i = 1; i <= m; i++) if (b[i] != b[m - i + 1]) return false;
  return true;
}
void solve() {
  scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int p = -1;
  for (int i = 1; i <= n; i++) if (a[i] != a[n - i + 1]) p = i;
  puts(p == -1 || del(a[p]) || del(a[n - p + 1]) ? "YES" : "NO");
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
}