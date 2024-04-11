#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, fa[100001][31], a[100001], deg[100001], p[100001], b[100001];
std::vector<int> c[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> fa[i][0], deg[fa[i][0]]++;
  for (int i = 1; i <= 30; i++)
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++)
    if (a[i] <= n) p[a[i]] = i;
  int lf = std::count(deg + 1, deg + n + 1, 0),
      rnd = (*std::max_element(a + 1, a + n + 1) - n) / lf;
  for (int i = 1; i <= n; i++) {
    int u = i;
    for (int j = 0; j <= 30; j++)
      if (rnd >> j & 1) u = fa[u][j];
    c[u].emplace_back(i);
  }
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    if (p[i]) {
      b[c[p[i]][0]] = i;
      auto it = s.end();
      for (std::size_t j = 1; j < c[p[i]].size(); j++)
        it = s.emplace_hint(it, c[p[i]][j]);
    } else {
      b[*s.begin()] = i, s.erase(s.begin());
    }
  }
  for (int i = 1; i <= n; i++) std::cout << b[i] << ' ';
  return 0;
}