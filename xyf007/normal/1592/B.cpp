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
int T, n, x, a[100001], b[100001];
void Solve() {
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  for (int i = n - x + 1; i <= x; i++)
    if (a[i] != b[i]) {
      std::cout << "NO\n";
      return;
    }
  std::cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}