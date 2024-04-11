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
struct Node {
  int a, b, s;
} a[100001];
class FwneickTree {
 public:
  FwneickTree() {}
  void Init(int n) { n_ = n, std::memset(t_, 0, sizeof(t_)); }
  void Add(int x, int v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  int Query(int x) {
    int s = 0;
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  ~FwneickTree() {}

 private:
  int t_[305], n_;
} tt[305];
int T, n, m, c[305][305];
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n * m; i++) std::cin >> a[i].a, a[i].b = i;
  std::sort(a + 1, a + n * m + 1, [](const Node &lhs, const Node &rhs) {
    return lhs.a == rhs.a ? lhs.b < rhs.b : lhs.a < rhs.a;
  });
  for (int i = 1; i <= n * m; i++) a[i].s = i;
  for (int i = 1; i <= n; i++) tt[i].Init(m + 1);
  std::sort(a + 1, a + n * m + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.b < rhs.b; });
  int ans = 0;
  for (int i = 1; i <= n * m; i++) {
    int x = (a[i].s - 1) / m + 1, y = (a[i].s - 1) % m + 1;
    c[x][y] = a[i].a;
    ans += tt[x].Query(y), tt[x].Add(y, 1);
  }
  for (int i = 1; i <= n; i++)
    for (int l = 1, r; l <= m; l = r + 1) {
      r = l;
      while (r < m && c[i][r + 1] == c[i][l]) r++;
      int len = r - l + 1;
      ans -= len * (len - 1) / 2;
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