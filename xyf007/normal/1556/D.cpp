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
int n, k;
long long a[10001];
long long Or(int x, int y) {
  std::cout << "or " << x << ' ' << y << std::endl;
  long long ans;
  std::cin >> ans;
  return ans;
}
long long And(int x, int y) {
  std::cout << "and " << x << ' ' << y << std::endl;
  long long ans;
  std::cin >> ans;
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 2; i <= n; i++) a[i] = And(1, i) + Or(1, i);
  long long s = And(2, 3) + Or(2, 3);
  a[1] = (a[2] + a[3] - s) / 2;
  for (int i = 2; i <= n; i++) a[i] -= a[1];
  std::sort(a + 1, a + n + 1);
  std::cout << "finish " << a[k] << std::endl;
  return 0;
}