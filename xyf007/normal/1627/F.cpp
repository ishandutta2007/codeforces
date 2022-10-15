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
constexpr int kDx[] = {1, 0, -1, 0}, kDy[] = {0, 1, 0, -1};
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
struct Edge {
  int to, nxt, cost;
} e[4000001];
int T, n, k, E, head[500001], dis[500001];
void Add(int f, int t, int c) { e[E] = {t, head[f], c}, head[f] = E++; }
void Solve() {
  std::cin >> n >> k;
  int N = (k + 1) * (k + 1);
  auto id = [](int x, int y) { return x * (k + 1) + y; };
  E = 0, std::memset(head, -1, 4 * N);
  std::map<std::pair<int, int>, int> w;
  for (int i = 1; i <= n; i++) {
    std::pair<int, int> p1, p2, r1, r2;
    std::cin >> p1.first >> p1.second >> p2.first >> p2.second;
    if (p1 > p2) std::swap(p1, p2);
    r1 = {k - p1.first + 1, k - p1.second + 1};
    r2 = {k - p2.first + 1, k - p2.second + 1};
    if (r1 > r2) std::swap(r1, r2);
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    if (x1 == x2) {
      int u = id(x1 - 1, y1), v = id(x1, y1);
      w[{u, v}]++, w[{v, u}]++;
    } else {
      int u = id(x1, y1 - 1), v = id(x1, y1);
      w[{u, v}]++, w[{v, u}]++;
    }
    std::tie(x1, y1) = r1;
    std::tie(x2, y2) = r2;
    if (x1 == x2) {
      int u = id(x1 - 1, y1), v = id(x1, y1);
      w[{u, v}]++, w[{v, u}]++;
    } else {
      int u = id(x1, y1 - 1), v = id(x1, y1);
      w[{u, v}]++, w[{v, u}]++;
    }
  }
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++) {
      int u = id(i, j);
      if (u == N - 1) continue;
      for (int o = 0; o < 4; o++) {
        int x = i + kDx[o], y = j + kDy[o];
        if (x >= 0 && x <= k && y >= 0 && y <= k) {
          int v = id(x, y);
          if (w.count({u, v}))
            Add(u, v, w[{u, v}]);
          else
            Add(u, v, 0);
        }
      }
    }
  std::memset(dis, 0x3f, 4 * N);
  for (int i = 0; i <= k; i++) dis[id(0, i)] = 0;
  for (int i = 0; i <= k; i++) dis[id(i, 0)] = 0;
  for (int i = 0; i <= k; i++) dis[id(k, i)] = 0;
  for (int i = 0; i <= k; i++) dis[id(i, k)] = 0;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      q;
  for (int i = 0; i <= k; i++) q.emplace(0, id(0, i));
  for (int i = 0; i <= k; i++) q.emplace(0, id(i, 0));
  for (int i = 0; i <= k; i++) q.emplace(0, id(k, i));
  for (int i = 0; i <= k; i++) q.emplace(0, id(i, k));
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dis[u] < d) continue;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v])
        dis[v] = dis[u] + e[i].cost, q.emplace(dis[v], v);
    }
  }
  std::cout << n - dis[id(k / 2, k / 2)] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}