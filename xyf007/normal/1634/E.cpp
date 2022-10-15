// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
struct Edge {
  int to, nxt;
} e[2000001];
int n, m[400001], N, LIM, E = 2, head[400005], deg[400005];
bool vis[2000001], c[2000001];
std::vector<int> a[400001], b, ed[400001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u) {
  for (int &i = head[u]; i; i = e[i].nxt) {
    if (vis[i >> 1]) continue;
    vis[i >> 1] = true, c[i] = true;
    Dfs(e[i].to);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> m[i];
    a[i].resize(m[i]);
    for (int j = 0; j < m[i]; j++) std::cin >> a[i][j];
  }
  N = std::accumulate(m + 1, m + n + 1, 0);
  b.reserve(N);
  for (int i = 1; i <= n; i++)
    std::copy(a[i].begin(), a[i].end(), std::back_inserter(b));
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  LIM = b.size();
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m[i]; j++)
      a[i][j] = std::lower_bound(b.begin(), b.end(), a[i][j]) - b.begin() + 1;
  for (int i = 1; i <= n; i++) {
    ed[i].resize(m[i]);
    for (int j = 0; j < m[i]; j++) {
      ed[i][j] = E;
      Add(i, n + a[i][j]), Add(n + a[i][j], i);
      deg[i]++, deg[n + a[i][j]]++;
    }
  }
  for (int i = 1; i <= n + LIM; i++)
    if (deg[i] & 1) {
      std::cout << "NO";
      return 0;
    }
  std::cout << "YES\n";
  for (int i = 1; i <= n + LIM; i++) Dfs(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m[i]; j++) std::cout << "LR"[c[ed[i][j]]];
    std::cout << '\n';
  }
  return 0;
}