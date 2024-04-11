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
int n, m, p, q;
std::pair<long long, int> o[200001];
long long a, b, c, Q[10000001];
struct Edge {
  int u, v, op;
  long long w;
} e[301], ee[301];
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) { std::iota(fa_ + 1, fa_ + n + 1, 1); }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[51];
} dsu;
std::pair<long long, int> Solve(long long x) {
  dsu.Init(n);
  for (int i = 1; i <= m; i++) {
    ee[i].u = e[i].u, ee[i].v = e[i].v;
    ee[i].w = std::abs(e[i].w - x), ee[i].op = e[i].w > x ? -1 : 1;
  }
  std::sort(ee + 1, ee + m + 1, [](const Edge &lhs, const Edge &rhs) {
    return lhs.w == rhs.w ? lhs.op < rhs.op : lhs.w < rhs.w;
  });
  std::pair<long long, int> ans;
  for (int i = 1; i <= m; i++)
    if (dsu.Merge(ee[i].u, ee[i].v))
      ans.first += ee[i].w, ans.second += ee[i].op;
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) std::cin >> e[i].u >> e[i].v >> e[i].w;
  std::cin >> p >> q >> a >> b >> c;
  for (int i = 1; i <= p; i++) std::cin >> Q[i];
  for (int i = p + 1; i <= q; i++) Q[i] = (Q[i - 1] * a + b) % c;
  std::vector<long long> ev;
  ev.push_back(0LL), ev.push_back(100000000LL);
  for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j++) {
      long long d = std::abs(e[i].w - e[j].w), x = std::min(e[i].w, e[j].w);
      ev.push_back(x + d / 2);
      if (d & 1) ev.push_back(x + d / 2 + 1);
    }
  std::sort(ev.begin(), ev.end());
  ev.erase(std::unique(ev.begin(), ev.end()), ev.end());
  for (std::size_t i = 0; i < ev.size(); i++) o[i] = Solve(ev[i]);
  long long ans = 0LL;
  for (int i = 1; i <= q; i++) {
    int x = std::upper_bound(ev.begin(), ev.end(), Q[i]) - ev.begin() - 1;
    ans ^= o[x].first + (Q[i] - ev[x]) * o[x].second;
  }
  std::cout << ans;
  return 0;
}