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
long long a[100001], b[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  if (n <= 2) {
    std::cout << 0;
    return 0;
  }
  long long ans = std::numeric_limits<long long>::max();
  for (b[1] = a[1] - 1; b[1] <= a[1] + 1; b[1]++)
    for (b[2] = a[2] - 1; b[2] <= a[2] + 1; b[2]++) {
      long long d = b[2] - b[1];
      for (int i = 3; i <= n; i++) b[i] = b[i - 1] + d;
      bool f = true;
      for (int i = 3; i <= n; i++)
        if (std::abs(a[i] - b[i]) > 1) {
          f = false;
          break;
        }
      if (f) {
        long long s = 0LL;
        for (int i = 1; i <= n; i++) s += std::abs(a[i] - b[i]);
        checkmin(ans, s);
      }
    }
  if (ans == std::numeric_limits<long long>::max()) ans = -1;
  std::cout << ans;
  return 0;
}