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
  int a, b;
} a[500001];
int n, d, b[1000005], dp[1000005], l;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> d;
  for (int i = 1; i <= n; i++) std::cin >> a[i].a >> a[i].b;
  int tot = 0;
  for (int i = 1; i <= n; i++) b[++tot] = a[i].a, b[++tot] = a[i].b;
  b[++tot] = d;
  std::sort(b + 1, b + tot + 1);
  tot = std::unique(b + 1, b + tot + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i].a = std::lower_bound(b + 1, b + tot + 1, a[i].a) - b;
    a[i].b = std::lower_bound(b + 1, b + tot + 1, a[i].b) - b;
  }
  d = std::lower_bound(b + 1, b + tot + 1, d) - b;
  b[0] = d;
  std::sort(a + 1, a + n + 1, [](const Node &lhs, const Node &rhs) {
    return std::max(lhs.a, lhs.b) == std::max(rhs.a, rhs.b)
               ? lhs.a < rhs.a
               : std::max(lhs.a, lhs.b) < std::max(rhs.a, rhs.b);
  });
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].a < d) continue;
    ans++, checkmax(d, a[i].b);
  }
  std::cout << ans;
  return 0;
}