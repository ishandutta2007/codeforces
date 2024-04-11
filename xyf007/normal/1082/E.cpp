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
int n, c, a[500001], b[500001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> c;
  int cnt = 0, max = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x == c) {
      cnt++;
    } else {
      if (a[x] + b[x] - cnt >= 0)
        a[x] += b[x] - cnt;
      else
        a[x] = 0;
      b[x] = cnt;
      checkmax(max, ++a[x]);
    }
  }
  std::cout << cnt + max;
  return 0;
}