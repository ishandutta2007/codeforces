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
int n, a[200001];
std::vector<int> g[200001], bf[200001], af[200001], ans;
int Dfs(int u, int fa) {
  int tot = g[u].size();
  for (auto &&v : g[u])
    if (v != fa) {
      int d = Dfs(v, u);
      tot -= d;
      if (d)
        bf[u].emplace_back(v);
      else
        af[u].emplace_back(v);
    }
  return (tot & 1) ^ 1;
}
void Erase(int u) {
  for (auto &&x : bf[u]) Erase(x);
  std::cout << u << '\n';
  for (auto &&x : af[u]) Erase(x);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  int rt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i])
      g[i].emplace_back(a[i]), g[a[i]].emplace_back(i);
    else
      rt = i;
  }
  if (!Dfs(rt, 0)) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  Erase(rt);
  return 0;
}