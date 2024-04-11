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
long long w;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> w;
  long long min = 0LL, max = w, now = 0LL;
  for (int i = 1; i <= n; i++) {
    long long x;
    std::cin >> x;
    now += x;
    checkmin(max, w - now), checkmax(min, -now);
  }
  std::cout << std::max(max - min + 1, 0LL);
  return 0;
}