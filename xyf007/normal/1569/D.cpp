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
int T, n, m, k, a[200001], b[200001];
void Solve() {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::vector<int> cx(m + 1), cy(n + 1);
  std::vector<std::map<int, int>> mx(m + 1), my(n + 1);
  long long ans = 0LL;
  for (int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    int px = std::lower_bound(a + 1, a + n + 1, x) - a,
        py = std::lower_bound(b + 1, b + m + 1, y) - b;
    if (a[px] == x && b[py] == y) continue;
    if (a[px] == x) {
      ans += cx[py] - mx[py][x];
      cx[py]++, mx[py][x]++;
    } else {
      ans += cy[px] - my[px][y];
      cy[px]++, my[px][y]++;
    }
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}