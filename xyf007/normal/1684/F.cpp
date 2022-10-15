#include <cstddef>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, m, L[200001], a[200001], b[200001];
std::vector<int> pos[200001];
std::vector<std::pair<int, int>> d[200001];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::copy(a + 1, a + n + 1, b + 1);
  std::sort(b + 1, b + n + 1);
  int nn = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
  for (int i = 1; i <= n; i++) pos[i].clear();
  for (int i = 1; i <= n; i++) pos[a[i]].emplace_back(i);
  std::iota(L + 1, L + n + 1, 1);
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    checkmin(L[r], l);
  }
  for (int i = n - 1; i >= 1; i--) checkmin(L[i], L[i + 1]);
  for (int i = 1; i <= n; i++) d[i].clear();
  int st = n + 1;
  std::multiset<int> s;
  for (int i = 1; i <= n; i++)
    if (!pos[i].empty()) {
      for (int j = 0; j < (int)pos[i].size(); j++) {
        int x = pos[i][j],
            k = std::lower_bound(pos[i].begin(), pos[i].end(), L[x]) -
                pos[i].begin();
        if (j != k) {
          checkmin(st, pos[i][k + 1]), s.emplace(pos[i][j - 1]);
          d[pos[i][k] + 1].emplace_back(pos[i][j - 1], pos[i][j]);
        }
      }
    }
  if (st > n) {
    std::cout << "0\n";
    return;
  }
  int ans = n;
  for (int i = 1; i <= st; i++) {
    for (const auto &[u, v] : d[i]) {
      s.erase(s.lower_bound(u));
      s.emplace(v);
    }
    checkmin(ans, (*s.rbegin()) - i + 1);
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