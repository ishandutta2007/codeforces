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
int T, a, b;
void Solve() {
  std::cin >> a >> b;
  if ((a + b) & 1) {
    std::cout << "-1\n";
    return;
  }
  if (!a && !b) {
    std::cout << "0\n";
    return;
  }
  if (a == b)
    std::cout << "1\n";
  else
    std::cout << "2\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}