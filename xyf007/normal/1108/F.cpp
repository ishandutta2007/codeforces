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
struct Edge {
  int u, v, c;
} e[200001];
int n, m;
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
  int fa_[200001];
} T;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  T.Init(n);
  for (int i = 1; i <= m; i++) std::cin >> e[i].u >> e[i].v >> e[i].c;
  std::sort(e + 1, e + m + 1,
            [](const Edge &lhs, const Edge &rhs) { return lhs.c < rhs.c; });
  int ans = 0;
  for (int l = 1, r; l <= m; l = r + 1) {
    r = l;
    while (r < m && e[r + 1].c == e[l].c) r++;
    int cnt = 0;
    for (int i = l; i <= r; i++)
      if (T.Find(e[i].u) != T.Find(e[i].v)) cnt++;
    for (int i = l; i <= r; i++)
      if (T.Merge(e[i].u, e[i].v)) cnt--;
    ans += cnt;
  }
  std::cout << ans;
  return 0;
}