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
int T, n, k, a[400001];
void Solve() {
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) std::cin >> a[i];
  for (int i = 1; i <= k; i++) a[i] = n - a[i];
  std::sort(a + 1, a + k + 1);
  n--;
  for (int i = 1; i <= k; i++)
    if (n >= a[i]) {
      n -= a[i];
    } else {
      std::cout << i - 1 << '\n';
      return;
    }
  std::cout << k << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}