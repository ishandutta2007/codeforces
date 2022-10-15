#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
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
} e[12000001];
int n, a[200001], E, head[6000001], tot, dep[6000001];
std::unordered_map<int, int> mp;
bool vis[6000001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u, int f) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    dep[v] = dep[u] + 1, Dfs(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  std::memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++) std::cin >> a[i], mp[a[i]] = i;
  tot = n;
  for (int i = 1; i <= n; i++)
    while (a[i]) {
      long long lg = 31 - __builtin_clz(a[i]), x = 1 << lg, nxt;
      if (x < a[i]) x <<= 1;
      nxt = x - a[i];
      if (!mp[nxt]) mp[nxt] = ++tot;
      Add(mp[a[i]], mp[nxt]), Add(mp[nxt], mp[a[i]]);
      a[i] = nxt;
    }
  std::memset(vis, 0, sizeof(vis));
  Dfs(1, 0);
  int x = std::max_element(dep + 1, dep + n + 1) - dep;
  dep[x] = 0;
  std::memset(vis, 0, sizeof(vis));
  Dfs(x, 0);
  int y = std::max_element(dep + 1, dep + n + 1) - dep;
  std::cout << x << ' ' << y << ' ' << dep[y];
  return 0;
}