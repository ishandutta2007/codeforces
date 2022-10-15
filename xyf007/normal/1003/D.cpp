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
int n, q, a[200001], cnt[101], b[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[__builtin_ctz(a[i])]++;
  while (q--) {
    int x, ans = 0;
    std::cin >> x;
    for (int i = 30; i >= 0; i--) b[i] = (x >> i) & 1;
    for (int i = 30; i >= 0; i--) {
      b[i] += 2 * b[i + 1];
      int t = std::min(b[i], cnt[i]);
      ans += t, b[i] -= t;
    }
    if (b[0]) ans = -1;
    std::cout << ans << '\n';
  }
  return 0;
}