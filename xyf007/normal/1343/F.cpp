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
int T, n, p[201];
std::set<int> a[201], b[201];
bool Check(int x) {
  std::memset(p + 2, 0, 4 * (n - 1));
  for (int i = 1; i < n; i++) b[i] = a[i];
  p[1] = x;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < n; j++)
      if (!b[j].empty() && b[j].count(p[i - 1])) b[j].erase(p[i - 1]);
    int po = -1;
    for (int j = 1; j < n; j++)
      if (b[j].size() == 1) {
        bool f = true;
        for (int k = i - 1; k > i - static_cast<int>(a[j].size()); k--)
          if (!a[j].count(p[k])) {
            f = false;
            break;
          }
        if (f) {
          if (po == -1)
            po = j;
          else
            return false;
        }
      }
    if (po == -1) return false;
    p[i] = *b[po].begin();
  }
  for (int i = 1; i <= n; i++) std::cout << p[i] << " \n"[i == n];
  return true;
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i < n; i++) a[i].clear();
  for (int i = 1; i < n; i++) {
    int k, x;
    std::cin >> k;
    while (k--) std::cin >> x, a[i].emplace(x);
  }
  for (int i = 1; i <= n; i++)
    if (Check(i)) return;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}