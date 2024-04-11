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
long long n, k, s;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k >> s;
  if (s < k || s > k * (n - 1)) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  int now = 1;
  for (int i = k; i >= 1; i--) {
    long long x = (s + i - 1) / i;
    std::cout << ((k - i) & 1 ? now -= x : now += x) << ' ';
    s -= x;
  }
  return 0;
}