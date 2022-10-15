#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Edge {
  int to, nxt;
} e[200001];
int n, m, E, head[100001], dfn[100001], sz[100001], tot, cnt[400001],
    tag[400001], ans[100001];
std::vector<int> v[100001];
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  dfn[u] = ++tot;
  sz[u] = 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) {
      continue;
    }
    Dfs(v, u);
    sz[u] += sz[v];
  }
}
void Pushup(int l, int r, int x) {
  if (tag[x]) {
    cnt[x] = r - l + 1;
  } else {
    if (l == r) {
      cnt[x] = 0;
    } else {
      cnt[x] = cnt[x + x] + cnt[x + x + 1];
    }
  }
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    tag[x] += v;
    Pushup(l, r, x);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) {
    Modify(L, R, l, mid, v, x + x);
  }
  if (R > mid) {
    Modify(L, R, mid + 1, r, v, x + x + 1);
  }
  Pushup(l, r, x);
}
void Solve(int u, int fa) {
  for (auto &&i : v[u]) {
    Modify(dfn[i], dfn[i] + sz[i] - 1, 1, n, 1, 1);
  }
  ans[u] = cnt[1];
  if (ans[u]) {
    ans[u]--;
  }
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) {
      continue;
    }
    Solve(v, u);
  }
  for (auto &&i : v[u]) {
    Modify(dfn[i], dfn[i] + sz[i] - 1, 1, n, -1, 1);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v);
    Add(v, u);
  }
  Dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    v[x].emplace_back(x);
    v[x].emplace_back(y);
    v[y].emplace_back(x);
    v[y].emplace_back(y);
  }
  Solve(1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " ";
  }
  return 0;
}