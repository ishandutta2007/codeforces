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
int n, a[500001], tot;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  double sum = 0.0, ans = 0.0;
  int r = 0, cnt = 1;
  for (int i = 1; i <= n; i++) {
    int op;
    std::cin >> op;
    if (op == 1) {
      std::cin >> a[++tot];
      sum += a[tot] - a[tot - 1];
      while (r + 1 < tot && a[r + 1] < sum / cnt) sum += a[++r], cnt++;
      ans = a[tot] - sum / cnt;
    } else {
      std::cout << std::setprecision(8) << std::fixed << ans << '\n';
    }
  }
  return 0;
}