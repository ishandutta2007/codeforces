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
int n, m, a[100001], max[400001], tag[400001];
std::vector<std::pair<int, int>> in[100001], de[100001];
void Pushup(int x) { max[x] = std::max(max[x + x], max[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x]) {
    max[x + x] += tag[x], max[x + x + 1] += tag[x];
    tag[x + x] += tag[x], tag[x + x + 1] += tag[x];
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    max[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    max[x] += v, tag[x] += v;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
  Pushup(x);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    in[l].emplace_back(r, i), de[r].emplace_back(l, i);
  }
  Build(1, n, 1);
  std::set<int> now, sol;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &&[r, id] : in[i]) Modify(i, r, 1, n, -1, 1), now.emplace(id);
    if (int s = max[1] - a[i] + static_cast<int>(now.size()); s > ans)
      ans = s, sol = now;
    for (auto &&[l, id] : de[i]) Modify(l, i, 1, n, 1, 1), now.erase(id);
  }
  std::cout << ans << '\n' << sol.size() << '\n';
  for (auto &&i : sol) std::cout << i << ' ';
  return 0;
}