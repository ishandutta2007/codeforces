#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, d, fa[5001], lg[5001];
bool vis[5001];
void Solve() {
  std::cin >> n >> d;
  if (d > n * (n - 1) / 2) {
    std::cout << "NO\n";
    return;
  }
  int tot = 0;
  for (int i = 2; i <= n; i++) fa[i] = i >> 1, tot += lg[i];
  if (d < tot) {
    std::cout << "NO\n";
    return;
  }
  std::memset(vis + 1, 0, n);
  int nowd = lg[n], bot = n;
  for (int i = n; i; i >>= 1) vis[i] = true;
  for (int i = n - 1; i > 1 && tot != d; i--) {
    if (vis[i]) continue;
    int delta = nowd + 1 - lg[i];
    if (tot + delta < d) {
      tot += delta, fa[i] = bot, nowd++, bot = i;
    } else {
      int aim = d - tot + lg[i], x = nowd + 1, f = bot;
      while (x > aim) x--, f = fa[f];
      fa[i] = f;
      break;
    }
  }
  std::cout << "YES\n";
  for (int i = 2; i <= n; i++) std::cout << fa[i] << " \n"[i == n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  for (int i = 2; i <= 5000; i++) lg[i] = lg[i >> 1] + 1;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}