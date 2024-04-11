#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <iostream>
#include <numeric>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, p;
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
  int size(int x) const { return sz_[x]; }
  ~DisjointSet() {}

 private:
  int fa_[100001], sz_[100001];
} dsu;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> p;
  dsu.Init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    dsu.Merge(u, v);
  }
  int k = 0;
  long long s = 1LL;
  for (int i = 1; i <= n; i++)
    if (dsu.Find(i) == i) k++, s = s * dsu.size(i) % p;
  if (k == 1) {
    std::cout << 1 % p;
  } else {
    for (int i = 1; i <= k - 2; i++) s = s * n % p;
    std::cout << s;
  }
  return 0;
}