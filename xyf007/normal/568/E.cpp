#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, k, a[100005], b[100005], f[100005], l[100005], p[100005], g[100005],
    ans[100005];
bool vis[100005];
int Use(int x) {
  int pos = std::lower_bound(b + 1, b + m + 1, x) - b - 1;
  vis[pos] = true;
  return b[pos];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  a[++n] = 0x3f3f3f3f;
  std::fill(f + 1, f + n + 1, 0x3f3f3f3f);
  std::cin >> m;
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      int j = std::lower_bound(f + 1, f + n + 1, a[i]) - f - 1;
      l[i] = j + 1, p[i] = g[j];
      f[j + 1] = a[i], g[j + 1] = i;
    } else {
      for (int o = m, j = n; o >= 1; o--) {
        while (f[j] >= b[o]) j--;
        f[j + 1] = b[o], g[j + 1] = i;
      }
    }
  }
  std::copy(a + 1, a + n + 1, ans + 1);
  for (int i = l[n], p0 = n, x = a[n]; i >= 2; i--) {
    if (a[p0] != -1) {
      p0 = p[p0];
      if (a[p0] != -1) {
        x = a[p0];
      } else {
        ans[p0] = x = Use(x);
      }
    } else {
      bool ok = false;
      for (int o = p0 - 1; o >= 1; o--)
        if (a[o] != -1 && a[o] < x && l[o] == i - 1) {
          x = a[p0 = o], ok = true;
          break;
        }
      if (ok) continue;
      for (int o = p0 - 1; o >= 1; o--)
        if (a[o] == -1) {
          ans[p0 = o] = x = Use(x);
          break;
        }
    }
  }
  for (int i = 1, j = 1; i < n; i++)
    if (ans[i] == -1) {
      while (vis[j]) j++;
      ans[i] = b[j++];
    }
  for (int i = 1; i < n; i++) std::cout << ans[i] << ' ';
  return 0;
}