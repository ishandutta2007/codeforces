#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
constexpr long double kEps = 1e-8;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Car {
  int x, y, dx, dy, s;
  long double l;
} a[25001];
int n, tot;
long double curx;
std::pair<long double, int> c[50001];
struct Segment {
  long double x1, y1, x2, y2;
} b[25001];
struct Cmp {
  bool operator()(const Segment &lhs, const Segment &rhs) const {
    return (lhs.y2 - lhs.y1) / (lhs.x2 - lhs.x1) * (curx - lhs.x1) + lhs.y1 <
           (rhs.y2 - rhs.y1) / (rhs.x2 - rhs.x1) * (curx - rhs.x1) + rhs.y1;
  }
};
std::set<Segment, Cmp>::iterator pos[25001];
bool IsIntersecting(const Segment &lhs, const Segment &rhs) {
  long double xl = std::max(lhs.x1, rhs.x1), xr = std::min(lhs.x2, rhs.x2);
  if (xl > xr + kEps) return false;
  long double k1 = (lhs.y2 - lhs.y1) / (lhs.x2 - lhs.x1),
              k2 = (rhs.y2 - rhs.y1) / (rhs.x2 - rhs.x1),
              yl1 = k1 * (xl - lhs.x1) + lhs.y1,
              yl2 = k2 * (xl - rhs.x1) + rhs.y1,
              yr1 = k1 * (xr - lhs.x1) + lhs.y1,
              yr2 = k2 * (xr - rhs.x1) + rhs.y1;
  if (std::fabs(yl1 - yl2) < kEps || std::fabs(yr1 - yr2) < kEps) return true;
  return (yl1 > yl2) ^ (yr1 > yr2);
}
bool Check(long double x) {
  tot = 0;
  for (int i = 1; i <= n; i++) {
    b[i].x1 = a[i].x, b[i].y1 = a[i].y;
    long double t = x * a[i].s / a[i].l;
    b[i].x2 = a[i].x + a[i].dx * t, b[i].y2 = a[i].y + a[i].dy * t;
    if (b[i].x1 > b[i].x2)
      std::swap(b[i].x1, b[i].x2), std::swap(b[i].y1, b[i].y2);
    c[++tot] = {b[i].x1, i}, c[++tot] = {b[i].x2, -i};
  }
  std::sort(c + 1, c + tot + 1);
  std::set<Segment, Cmp> s;
  for (int i = 1; i <= tot; i++) {
    curx = c[i].first;
    int u = std::abs(c[i].second);
    if (c[i].second > 0) {
      auto it = s.lower_bound(b[u]);
      if (it != s.end())
        if (IsIntersecting(b[u], *it)) return true;
      if (it != s.begin())
        if (IsIntersecting(b[u], *--it)) return true;
      pos[u] = s.emplace_hint(it, b[u]);
    } else {
      if (auto it = s.erase(pos[u]); it != s.end() && it != s.begin()) {
        auto nxt = *it, pre = *std::prev(it);
        if (IsIntersecting(pre, nxt)) return true;
      }
    }
  }
  return false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y >> a[i].dx >> a[i].dy >> a[i].s;
    a[i].l = std::hypotl(a[i].dx, a[i].dy);
  }
  long double l = 0.0L, r = 1000000000000.0L;
  while (l + kEps < r) {
    long double mid = (l + r) / 2;
    (Check(mid) ? r : l) = mid;
  }
  if (l > 900000000000) {
    std::cout << "No show :(";
  } else {
    std::cout.precision(8), std::cout << std::fixed << l;
  }
  return 0;
}