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
int n;
long long k, a[500001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  long long sum = std::accumulate(a + 1, a + n + 1, 0LL), avg = sum / n;
  auto [p1, p2] = std::minmax_element(a + 1, a + n + 1);
  long long min = *p1, max = *p2, amax = 0LL, amin = 0LL;
  auto check1 = [](long long x) {
    long long tot = 0LL;
    for (int i = 1; i <= n; i++) tot += std::max(a[i] - x, 0LL);
    return tot <= k;
  };
  long long l = avg + !!(sum % n), r = max;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check1(mid)) {
      amax = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  auto check2 = [](long long x) {
    long long tot = 0LL;
    for (int i = 1; i <= n; i++) tot += std::max(x - a[i], 0LL);
    return tot <= k;
  };
  l = min, r = avg;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check2(mid)) {
      amin = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  std::cout << amax - amin;
  return 0;
}