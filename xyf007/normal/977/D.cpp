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
std::vector<long long> p[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    std::cin >> x;
    p[__builtin_ctzll(x)].emplace_back(x);
  }
  for (int i = 0; i <= 100; i++) {
    std::sort(p[i].begin(), p[i].end(), std::greater<long long>());
    for (auto &&x : p[i]) std::cout << x << ' ';
  }
  return 0;
}