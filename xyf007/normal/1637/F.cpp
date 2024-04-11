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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
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
int n, rt;
long long h[200001], f[200001], max[200001];
std::vector<int> g[200001];
void Dfs(int u, int fa) {
  if (g[u].size() == 1) {
    f[u] = h[u];
    max[u] = h[u];
    return;
  }
  for (const auto &v : g[u]) {
    if (v == fa) continue;
    Dfs(v, u), checkmax(max[u], max[v]);
    f[u] += f[v];
  }
  if (max[u] < h[u]) f[u] += h[u] - max[u], max[u] = h[u];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> h[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  rt = std::max_element(h + 1, h + n + 1) - h;
  std::vector<int> v, s;
  for (const auto &u : g[rt]) Dfs(u, rt), v.push_back(u), s.push_back(max[u]);
  long long ans = 0LL;
  for (const auto &u : g[rt]) ans += f[u];
  std::sort(s.begin(), s.end(), std::greater());
  if (s.size() == 1) s.push_back(0);
  ans += h[rt] - s[0] + h[rt] - s[1];
  std::cout << ans;
  return 0;
}