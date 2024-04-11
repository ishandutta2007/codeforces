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
int T, n, a[200001], b[200001];
class FenwickTree {
 public:
  FenwickTree(int n) { n_ = n, std::memset(t_, 0, 4 * (n_ + 1)); }
  void Add(int x, int v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  int Query(int x) {
    int s = 0;
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  ~FenwickTree() {}

 private:
  int n_, t_[200001];
};
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  int nn = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
  FenwickTree T(nn);
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans += std::min(T.Query(a[i] - 1), i - 1 - T.Query(a[i]));
    T.Add(a[i], 1);
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