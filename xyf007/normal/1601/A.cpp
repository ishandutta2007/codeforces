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
int T, n, a[200001];
std::vector<int> d[200001];
void Init(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) d[j].emplace_back(i);
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::array<int, 31> cnt;
  for (int i = 0; i < 30; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 30; j++)
      if ((a[i] >> j) & 1) cnt[j]++;
  int g = 0;
  for (int i = 0; i < 30; i++) g = std::gcd(g, cnt[i]);
  if (!g) {
    for (int i = 1; i <= n; i++) std::cout << i << " \n"[i == n];
    return;
  }
  for (auto &&x : d[g]) std::cout << x << ' ';
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(200000);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}