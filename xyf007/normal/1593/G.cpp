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
int T, n, q;
std::pair<int, int> c[4000001];
char s[1000005];
std::pair<int, int> operator+(const std::pair<int, int> &lhs,
                              const std::pair<int, int> &rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
std::pair<int, int> &operator+=(std::pair<int, int> &lhs,
                                const std::pair<int, int> &rhs) {
  lhs.first += rhs.first, lhs.second += rhs.second;
  return lhs;
}
void Pushup(int x) { c[x] = c[x + x] + c[x + x + 1]; }
void Build(int l, int r, int x) {
  c[x] = {0, 0};
  if (l == r) {
    if (s[l] == '[' || s[l] == ']') (l & 1 ? c[x].first : c[x].second) = 1;
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
std::pair<int, int> Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return c[x];
  int mid = (l + r) >> 1;
  std::pair<int, int> ans;
  if (L <= mid) ans += Query(L, R, l, mid, x + x);
  if (R > mid) ans += Query(L, R, mid + 1, r, x + x + 1);
  return ans;
}
void Solve() {
  std::cin >> (s + 1) >> q, n = std::strlen(s + 1);
  Build(1, n, 1);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    auto ans = Query(l, r, 1, n, 1);
    std::cout << std::abs(ans.first - ans.second) << '\n';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}