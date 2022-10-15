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
struct Node {
  int op, x, y;
} b[100001], c[100001];
int n, m, q, tot, rev[100001], ans[100001], tag[1001], a[1001][1001], s[1001];
std::vector<int> g[100001];
void Dfs(int u) {
  int x = c[u].x, y = c[u].y, pre = -1;
  if (c[u].op == 1) {
    pre = a[x][y];
    if (!(a[x][y] ^ tag[x])) ans[u]++, a[x][y] = 1 ^ tag[x], s[x]++;
  } else if (c[u].op == 2) {
    pre = a[x][y];
    if (a[x][y] ^ tag[x]) ans[u]--, a[x][y] = tag[x], s[x]--;
  } else if (c[u].op == 3) {
    tag[x] ^= 1;
    ans[u] += m - s[x] - s[x];
    s[x] = m - s[x];
  }
  for (auto &&v : g[u]) {
    ans[v] = ans[u];
    Dfs(v);
  }
  if (c[u].op == 1) {
    if (!(pre ^ tag[x])) s[x]--;
    a[x][y] = pre;
  } else if (c[u].op == 2) {
    if (pre ^ tag[x]) s[x]++;
    a[x][y] = pre;
  } else if (c[u].op == 3) {
    tag[x] ^= 1;
    s[x] = m - s[x];
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  int now = 0;
  for (int i = 1; i <= q; i++) {
    std::cin >> b[i].op >> b[i].x;
    if (b[i].op <= 2) std::cin >> b[i].y;
    if (b[i].op != 4) {
      g[now].emplace_back(++tot);
      c[rev[i] = now = tot] = b[i];
    } else {
      rev[i] = now = rev[b[i].x];
    }
  }
  Dfs(0);
  for (int i = 1; i <= q; i++) std::cout << ans[rev[i]] << '\n';
  return 0;
}