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
int T, n, d, a[1000001], dis[1000001];
bool vis[1000001];
bool Calc(int x) {
  std::vector<int> cyc;
  while (!vis[x]) cyc.emplace_back(x), vis[x] = true, x = (x + d) % n;
  if (std::all_of(cyc.begin(), cyc.end(),
                  [](const int &x) { return a[x] == 1; }))
    return false;
  int p = -1;
  for (std::size_t i = 0; i < cyc.size(); i++)
    if (!a[cyc[i]]) {
      p = i;
      break;
    }
  std::rotate(cyc.begin(), cyc.begin() + p, cyc.end());
  int cnt = 0;
  for (std::size_t i = 0; i < cyc.size(); i++) {
    a[cyc[i]] ? cnt++ : cnt = 0;
    dis[cyc[i]] = cnt;
  }
  return true;
}
void Solve() {
  std::cin >> n >> d;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::memset(vis, 0, n);
  std::memset(dis, 0, 4 * n);
  for (int i = 0; i < n; i++)
    if (!vis[i])
      if (!Calc(i)) {
        std::cout << "-1\n";
        return;
      }
  std::cout << *std::max_element(dis, dis + n) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}