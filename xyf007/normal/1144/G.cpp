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
int n, a[200001], f[200001], g[200001], ans[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(f, 0x3f, sizeof(f)), std::memset(g, 0xcf, sizeof(g));
  f[1] = -808464433, g[1] = 0x3f3f3f3f;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] > a[i]) checkmin(f[i], f[i - 1]);
    if (g[i - 1] > a[i]) checkmin(f[i], a[i - 1]);
    if (a[i - 1] < a[i]) checkmax(g[i], g[i - 1]);
    if (f[i - 1] < a[i]) checkmax(g[i], a[i - 1]);
  }
  if (f[n] == 0x3f3f3f3f && g[n] == -808464433) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  int op = f[n] != 0x3f3f3f3f;
  for (int i = n; i >= 1; i--) {
    ans[i] = op;
    if (op)
      op = f[i] == f[i - 1] ? 1 : 0;
    else
      op = g[i] == g[i - 1] ? 0 : 1;
  }
  for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
  return 0;
}