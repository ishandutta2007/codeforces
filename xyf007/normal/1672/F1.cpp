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
int T, n, a[200001], b[200001];
std::vector<int> p[200001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) p[i].clear();
  for (int i = 1; i <= n; i++) std::cin >> a[i], p[a[i]].emplace_back(i);
  std::vector<int> v;
  for (int i = 1; i <= n; i++)
    if (!p[i].empty()) v.emplace_back(i);
  while (!v.empty()) {
    std::vector<std::pair<int, int>> cir;
    for (const auto x : v) cir.emplace_back(x, p[x].back()), p[x].pop_back();
    int m = cir.size();
    for (int i = 0; i < m; i++) b[cir[(i + 1) % m].second] = cir[i].first;
    std::vector<int> vv;
    for (const auto x : v)
      if (!p[x].empty()) vv.emplace_back(x);
    std::swap(v, vv);
  }
  for (int i = 1; i <= n; i++) std::cout << b[i] << " \n"[i == n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}