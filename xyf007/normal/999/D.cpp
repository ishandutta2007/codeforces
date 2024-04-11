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
int n, m, a[200001];
std::vector<int> v[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    v[a[i] % m].emplace_back(i);
  }
  std::queue<int> q;
  unsigned int lim = n / m;
  long long ans = 0LL;
  for (int i = 0; i < m; i++) {
    while (v[i].size() > lim) q.emplace(v[i].back()), v[i].pop_back();
    while (!q.empty() && v[i].size() < lim) {
      int u = q.front(), pre = a[u] % m, d = (i - pre + m) % m;
      q.pop();
      v[i].emplace_back(u);
      ans += d, a[u] += d;
    }
  }
  for (int i = 0; i < m; i++) {
    while (v[i].size() > lim) q.emplace(v[i].back()), v[i].pop_back();
    while (!q.empty() && v[i].size() < lim) {
      int u = q.front(), pre = a[u] % m, d = (i - pre + m) % m;
      q.pop();
      v[i].emplace_back(u);
      ans += d, a[u] += d;
    }
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) std::cout << a[i] << ' ';
  return 0;
}