#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
struct MyHash {
  static std::uint64_t splitmix64(std::uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  std::size_t operator()(std::uint64_t x) const {
    static const std::chrono::steady_clock::rep FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int n, a[100001], B = 45;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int ans = 0;
  __gnu_pbds::gp_hash_table<int, int, MyHash> mp;
  for (int d = -B; d <= B; d++) {
    mp.clear();
    for (int i = 1; i <= n; i++) mp[a[i] - i * d]++;
    for (auto it = mp.begin(); it != mp.end(); ++it) checkmax(ans, it->second);
  }
  int T = 100000 / B + 1;
  for (int i = 1; i <= n; i++) {
    mp.clear();
    for (int j = std::min(i + T, n); j > i; j--)
      if ((a[j] - a[i]) % (j - i) == 0 && std::abs((a[j] - a[i]) / (j - i)) > B)
        mp[(a[j] - a[i]) / (j - i)]++;
    for (auto it = mp.begin(); it != mp.end(); ++it)
      checkmax(ans, it->second + 1);
  }
  std::cout << n - ans;
  return 0;
}