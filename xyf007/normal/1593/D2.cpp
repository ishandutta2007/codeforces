#include <algorithm>
#include <bitset>
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
int T, n, a[41], cnt[2000001];
std::vector<std::pair<int, int>> v[2000001];
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) {
    std::iota(fa_ + 1, fa_ + n + 1, 1), std::fill(sz_ + 1, sz_ + n + 1, 1);
  }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy, sz_[fy] += sz_[fx];
    return true;
  }
  int sz(int x) { return sz_[x]; }
  ~DisjointSet() {}

 private:
  int fa_[41], sz_[41];
} dsu;
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[a[i] += 1000000]++;
  bool f = false;
  for (int i = 1; i <= n; i++)
    if (cnt[a[i]] >= n / 2) {
      std::cout << "-1\n";
      goto ed;
    }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      int d = std::abs(a[i] - a[j]);
      for (int x = 1; x * x <= d; x++)
        if (!(d % x)) {
          v[x].emplace_back(i, j);
          if (x * x != d) v[d / x].emplace_back(i, j);
        }
    }
  for (int i = 2000000; i >= 1 && !f; i--) {
    dsu.Init(n);
    for (auto &&[x, y] : v[i]) dsu.Merge(x, y);
    for (int j = 1; j <= n; j++)
      if (dsu.sz(dsu.Find(j)) >= n / 2) {
        std::cout << i << '\n';
        f = true;
        break;
      }
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      int d = std::abs(a[i] - a[j]);
      for (int x = 1; x * x <= d; x++)
        if (!(d % x)) {
          v[x].clear();
          if (x * x != d) v[d / x].clear();
        }
    }
ed:;
  for (int i = 1; i <= n; i++) cnt[a[i]]--;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}