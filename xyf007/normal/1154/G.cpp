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
int n, a[1000001];
std::vector<int> p[10000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], p[a[i]].emplace_back(i);
  int N = *std::max_element(a + 1, a + n + 1), l = 1, r = 1;
  long long ans = 0x3f3f3f3f3f3f3f3fLL;
  for (int i = 1; i <= N && i <= ans; i++) {
    int pre = 0;
    for (int j = 1; j <= N / i; j++)
      if (p[i * j].size() > 1) {
        if (!pre) pre = j;
        if (long long tmp = static_cast<long long>(i) * pre * j; tmp < ans) {
          ans = tmp;
          l = p[pre * i].front(), r = p[j * i].back();
        }
        break;
      } else if (p[i * j].size() == 1) {
        if (!pre) {
          pre = j;
          continue;
        }
        if (long long tmp = static_cast<long long>(i) * pre * j; tmp < ans) {
          ans = tmp;
          l = p[pre * i].front(), r = p[j * i].back();
        }
        break;
      }
  }
  if (l > r) std::swap(l, r);
  std::cout << l << ' ' << r;
  return 0;
}