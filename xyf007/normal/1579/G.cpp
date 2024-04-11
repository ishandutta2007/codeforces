#include <algorithm>
#include <bitset>
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
int T, n, a[10001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int l = *std::max_element(a + 1, a + n + 1), r = 2 * l, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    std::bitset<3001> b, b0;
    for (int i = 0; i <= mid; i++) b0.set(i);
    b = b0;
    for (int i = 1; i <= n; i++)
      if (!(b = ((b << a[i]) | (b >> a[i])) & b0).any()) break;
    if (b.any())
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << best << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}