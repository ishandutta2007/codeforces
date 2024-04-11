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
struct Edge {
  int to, nxt;
} e[2001];
int n, E, head[1001], dfn[1001], tot, r[1001], m;
std::pair<int, int> ee[1001];
void Add(int f, int t) {
  e[E] = {t, head[f]};
  head[f] = E++;
}
void Dfs(int u, int fa) {
  r[dfn[u] = ++tot] = u;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    ee[++m] = {u, v}, Dfs(v, u);
  }
}
int Ask(const std::vector<int> &v) {
  std::cout << "? " << v.size();
  for (auto &&x : v) std::cout << ' ' << x;
  std::cout << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}
bool vis[2001], vv[2001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  std::memset(head, -1, sizeof(head));
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v), Add(v, u);
  }
  Dfs(1, 0);
  std::vector<int> v;
  for (int i = 1; i <= n; i++) v.emplace_back(i);
  int ans = Ask(v);
  int l = 1, r = m, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    std::vector<int> a;
    for (int i = l; i <= mid; i++)
      a.emplace_back(ee[i].first), a.emplace_back(ee[i].second);
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int res = Ask(a);
    if (res == ans)
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << "! " << ee[best].first << ' ' << ee[best].second << std::endl;
  return 0;
}