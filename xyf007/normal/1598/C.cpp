#include <algorithm>
#include <chrono>
#include <cmath>
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
constexpr long double kEps = 1e-8;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n;
long long a[200001];
struct MyHash {
  static std::uint64_t splitmix64(std::uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  std::size_t operator()(std::uint64_t x) const {
    static const std::chrono::_V2::steady_clock::rep FIXED_RANDOM =
        std::chrono::_V2::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  long long sum = std::accumulate(a + 1, a + n + 1, 0LL);
  long double mean = sum / static_cast<long double>(n), s = 2 * mean;
  if (std::fabs(s - std::round(s)) > kEps) {
    std::cout << "0\n";
    return;
  }
  long long x = std::round(s), ans = 0LL;
  std::unordered_map<long long, int, MyHash> mp;
  for (int i = 1; i <= n; i++) mp[a[i]]++;
  for (int i = 1; i <= n; i++)
    if (mp.count(x - a[i])) ans += mp[x - a[i]] - (a[i] == x - a[i]);
  std::cout << ans / 2 << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}