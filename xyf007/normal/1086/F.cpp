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
constexpr long long kMod = 998244353LL, kInv2 = 499122177LL,
                    kInv6 = 166374059LL;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  long long x, y;
} a[51];
struct Square {
  long long x1, y1, x2, y2;
} sq[51];
int n, tot, vis[101];
long long t, tm[100001], x[101], y[101];
long long Calc(long long T) {
  int cx = 0, cy = 0;
  for (int i = 1; i <= n; i++) {
    sq[i] = {a[i].x - T, a[i].y - T, a[i].x + T, a[i].y + T};
    x[++cx] = sq[i].x1, y[++cy] = sq[i].y1;
    x[++cx] = sq[i].x2 + 1, y[++cy] = sq[i].y2 + 1;
  }
  std::sort(x + 1, x + cx + 1), std::sort(y + 1, y + cy + 1);
  cx = std::unique(x + 1, x + cx + 1) - x - 1;
  cy = std::unique(y + 1, y + cy + 1) - y - 1;
  std::vector<std::tuple<int, int, int>> v[101];
  for (int i = 1; i <= n; i++) {
    int x1 = std::lower_bound(x + 1, x + cx + 1, sq[i].x1) - x,
        y1 = std::lower_bound(y + 1, y + cy + 1, sq[i].y1) - y,
        x2 = std::lower_bound(x + 1, x + cx + 1, sq[i].x2 + 1) - x,
        y2 = std::lower_bound(y + 1, y + cy + 1, sq[i].y2 + 1) - y;
    v[x1].emplace_back(y1, y2, 1);
    v[x2].emplace_back(y1, y2, -1);
  }
  std::memset(vis, 0, sizeof(vis));
  long long ans = 0LL;
  for (int i = 1; i < cx; i++) {
    for (auto &&[l, r, op] : v[i])
      for (int j = l; j < r; j++) vis[j] += op;
    long long cur = 0LL;
    for (int i = 1; i < cy; i++)
      if (vis[i]) cur += y[i + 1] - y[i];
    Add(ans, mul(cur, x[i + 1] - x[i]));
  }
  return ans;
}
inline long long s1(long long x) { return mul(x, x + 1, kInv2); }
inline long long s1(long long l, long long r) { return s1(r) - s1(l - 1); }
inline long long s2(long long x) { return mul(x, x + 1, 2 * x + 1, kInv6); }
inline long long s2(long long l, long long r) { return s2(r) - s2(l - 1); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> t;
  tm[++tot] = 0, tm[++tot] = t + 1;
  for (int i = 1; i <= n; i++) std::cin >> a[i].x >> a[i].y;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      int dx = std::abs(a[i].x - a[j].x), dy = std::abs(a[i].y - a[j].y);
      tm[++tot] = (std::max(dx, dy) + 1) >> 1;
    }
  std::sort(tm + 1, tm + tot + 1);
  tot = std::unique(tm + 1, tm + tot + 1) - tm - 1;
  long long ans = t * Calc(t);
  for (int i = 1; i < tot; i++) {
    if (tm[i] > t) break;
    if (tm[i + 1] - tm[i] < 3) {
      for (int j = tm[i]; j < tm[i + 1]; j++)
        if (j < t) ans -= Calc(j);
      continue;
    }
    long long x1 = tm[i], y1 = Calc(x1), x2 = tm[i] + 1, y2 = Calc(x2),
              x3 = tm[i] + 2, y3 = Calc(x3),
              A = mul(sub(add(y1, y3), y2, y2), kInv2),
              B = sub(y2, y1, mul(A, sub(mul(x2, x2), mul(x1, x1)))),
              C = sub(y1, mul(A, x1, x1), mul(B, x1)), l = tm[i],
              r = std::min(tm[i + 1], t) - 1;
    Sub(ans, mul(A, s2(l, r)), mul(B, s1(l, r)), mul(C, r - l + 1));
  }
  std::cout << ans;
  return 0;
}