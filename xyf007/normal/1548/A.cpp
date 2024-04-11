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
int n, m, q, cnt[200001];
bool vis[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    if (u > v) std::swap(u, v);
    cnt[u]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!cnt[i]) ans++;
  std::cin >> q;
  while (q--) {
    int op, u, v;
    std::cin >> op;
    if (op == 1) {
      std::cin >> u >> v;
      if (u > v) std::swap(u, v);
      ans -= !cnt[u]++;
    } else if (op == 2) {
      std::cin >> u >> v;
      if (u > v) std::swap(u, v);
      ans += !--cnt[u];
    } else {
      std::cout << ans << '\n';
    }
  }
  return 0;
}