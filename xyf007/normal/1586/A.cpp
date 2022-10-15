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
int T, n, a[2001];
bool np[20001];
void Init(int n) {
  for (int i = 2; i <= n; i++)
    if (!np[i])
      for (int j = i + i; j <= n; j += i) np[j] = true;
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int sum = std::accumulate(a + 1, a + n + 1, 0);
  if (np[sum]) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) std::cout << i << " \n"[i == n];
    return;
  }
  for (int i = 1; i <= n; i++)
    if (np[sum - a[i]]) {
      std::cout << n - 1 << '\n';
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        std::cout << j << ' ';
      }
      std::cout << '\n';
      return;
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(20000);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}