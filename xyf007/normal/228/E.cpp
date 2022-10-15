#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Edge {
  int to, nxt;
} e[40001];
int n, m, E, head[201], dfn[201], low[201], tot, col[201], c, s[201], top;
bool vis[201];
std::vector<int> v;
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u;
  vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v]) {
      Tarjan(v);
      checkmin(low[u], low[v]);
    } else if (vis[v]) {
      checkmin(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    col[u] = ++c;
    vis[u] = false;
    while (s[top] != u) {
      col[s[top]] = c;
      vis[s[top--]] = false;
    }
    top--;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    if (c) {
      Add(u + n, v + n);
      Add(u, v);
      Add(v + n, u + n);
      Add(v, u);
    } else {
      Add(u, v + n);
      Add(u + n, v);
      Add(v, u + n);
      Add(v + n, u);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!dfn[i]) {
      Tarjan(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] == col[i + n]) {
      std::cout << "Impossible";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] > col[n + i]) {
      v.emplace_back(i);
    }
  }
  std::cout << v.size() << '\n';
  for (auto &&i : v) {
    std::cout << i << ' ';
  }
  return 0;
}