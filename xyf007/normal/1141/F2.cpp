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
struct Interval {
  int l, r, v;
} b[2000001];
int n, a[1501], sum[1501], tot;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) b[++tot] = {i, j, sum[j] - sum[i - 1]};
  std::sort(b + 1, b + tot + 1, [](const Interval &lhs, const Interval &rhs) {
    return lhs.v == rhs.v ? lhs.r < rhs.r : lhs.v < rhs.v;
  });
  unsigned int ans = 0;
  std::vector<Interval> sol;
  for (int l = 1, r; l <= tot; l = r + 1) {
    r = l;
    while (r < tot && b[r + 1].v == b[l].v) r++;
    int p = 0;
    std::vector<Interval> tmp;
    for (int i = l; i <= r; i++)
      if (b[i].l <= p)
        continue;
      else
        tmp.emplace_back(b[i]), p = b[i].r;
    if (tmp.size() > ans) ans = tmp.size(), sol = tmp;
  }
  std::cout << ans << '\n';
  for (auto &&i : sol) std::cout << i.l << ' ' << i.r << '\n';
  return 0;
}