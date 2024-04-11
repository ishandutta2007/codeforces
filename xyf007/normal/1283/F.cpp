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
int n, a[200001], fir[200001], fa[200001], b[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i < n; i++) std::cin >> a[i];
  for (int i = n - 1; i >= 1; i--) fir[a[i]] = i;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      q;
  std::iota(b + 1, b + n + 1, 1);
  for (int i = 1; i <= n; i++)
    if (!fir[i]) q.emplace(b[i], i);
  for (int i = n - 1; i >= 1; i--) {
    auto tmp = q.top();
    q.pop();
    auto [x, u] = tmp;
    fa[u] = a[i];
    checkmax(b[a[i]], x);
    if (i == fir[a[i]]) q.emplace(b[a[i]], a[i]);
  }
  int rt = q.top().second;
  std::cout << rt << '\n';
  for (int i = 1; i <= n; i++)
    if (i != rt) std::cout << fa[i] << ' ' << i << '\n';
  return 0;
}