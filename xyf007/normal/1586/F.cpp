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
int k, n;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  int c = 0, m = 1;
  while (m < n) m *= k, c++;
  std::cout << c << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int u = i, v = j, r = 0;
      while (u != v) u /= k, v /= k, r++;
      std::cout << r << ' ';
    }
  return 0;
}