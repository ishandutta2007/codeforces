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
int n, a[101], ans[101];
int Ask() {
  std::cout << '?';
  for (int i = 1; i <= n; i++) std::cout << ' ' << a[i];
  std::cout << std::endl;
  int k;
  std::cin >> k;
  return k;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) a[i] = 1;
  std::vector<int> p(1, 0);
  for (int i = 2; i <= n; i++) {
    a[n] = i;
    p.emplace_back(Ask());
  }
  int las = 0;
  for (int i = 1; i < n; i++)
    if (p[i]) las = i;
  int now = n;
  for (int i = las; i >= 1; i--) ans[p[i]] = now--;
  ans[n] = now--;
  std::vector<int>(1, 0).swap(p);
  a[n] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < n; j++) a[j] = i;
    p.emplace_back(Ask());
  }
  for (int i = 1; i < n; i++)
    if (p[i]) ans[p[i]] = now--;
  std::cout << '!';
  for (int i = 1; i <= n; i++) std::cout << ' ' << ans[i];
  std::cout << std::endl;
  return 0;
}