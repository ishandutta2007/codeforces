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
int n, m, tot, b[100001], p[100001];
bool Check(int x) {
  long long rem = tot;
  for (int i = 1; i <= x; i++)
    if (b[i] < p[x - i + 1]) rem -= p[x - i + 1] - b[i];
  return rem >= 0LL;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> tot;
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  for (int i = 1; i <= m; i++) std::cin >> p[i];
  std::sort(b + 1, b + n + 1, std::greater<int>());
  std::sort(p + 1, p + m + 1);
  int l = 0, r = std::min(n, m), best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (!best)
    std::cout << "0 0";
  else
    std::cout << best << ' '
              << std::max(std::accumulate(p + 1, p + best + 1, 0LL) - tot, 0LL);
  return 0;
}