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
int n, m, k, b[200001];
std::tuple<long long, int, int> e[200001];
long long dis[1001][1001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long c;
    std::cin >> u >> v >> c;
    e[i] = {c, u, v};
  }
  std::sort(e + 1, e + m + 1);
  std::vector<int> a;
  for (int i = 1; i <= k && i <= m; i++)
    a.emplace_back(std::get<1>(e[i])), a.emplace_back(std::get<2>(e[i]));
  std::sort(a.begin(), a.end());
  auto it = std::unique(a.begin(), a.end());
  a.erase(it, a.end());
  int nn = a.size();
  for (int i = 1; i <= nn; i++) b[a[i - 1]] = i;
  std::memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= nn; i++) dis[i][i] = 0LL;
  for (int i = 1; i <= k && i <= m; i++) {
    auto [c, u, v] = e[i];
    dis[b[u]][b[v]] = dis[b[v]][b[u]] = c;
  }
  for (int l = 1; l <= nn; l++)
    for (int i = 1; i <= nn; i++)
      for (int j = 1; j <= nn; j++) checkmin(dis[i][j], dis[i][l] + dis[l][j]);
  std::vector<long long> alld;
  for (int i = 1; i < nn; i++)
    for (int j = i + 1; j <= nn; j++) alld.emplace_back(dis[i][j]);
  std::sort(alld.begin(), alld.end());
  std::cout << alld[k - 1];
  return 0;
}