#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int to, nxt, cost;
} e[400001];
int n, E, head[200001], dfn[200001], low[200001], tot, s[200001], top, c, pos;
long long sum[200001], dep[200001], maxd[200001], pre[200001], suf[200001],
    pree[200001], suff[200001], md;
bool vis[200001];
std::vector<int> cyc[200001];
void Add(int f, int t, int c) { e[E] = {t, head[f], c}, head[f] = E++; }
void Tarjan(int u, int fa) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u, vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    if (!dfn[v])
      Tarjan(v, u), checkmin(low[u], low[v]);
    else if (vis[v])
      checkmin(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    c++;
    while (s[top] != u) cyc[c].emplace_back(s[top]), vis[s[top--]] = false;
    cyc[c].emplace_back(u), top--, vis[u] = false;
  }
}
bool incyc[200001], use[200001];
void Dfs(int u, int fa, int rt) {
  if (dep[u] > md) md = dep[u], pos = u;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa || (incyc[v] && v != rt)) continue;
    dep[v] = dep[u] + e[i].cost, Dfs(v, u, rt);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  std::memset(head + 1, -1, 4 * n);
  for (int i = 1; i <= n; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    Add(u, v, c), Add(v, u, c);
  }
  Tarjan(1, 1);
  std::vector<int> cc;
  for (int i = 1; i <= c; i++)
    if (cyc[i].size() > 1) {
      cc = cyc[i];
      break;
    }
  for (const auto &i : cc) incyc[i] = true;
  int sz = cc.size();
  for (int i = 0; i + 1 < sz; i++) {
    int u = cc[i];
    for (int j = head[u]; j != -1; j = e[j].nxt) {
      int v = e[j].to;
      if (v == cc[i + 1]) {
        sum[i + 1] = e[j].cost, use[j >> 1] = true;
        break;
      }
    }
  }
  std::partial_sum(sum, sum + sz, sum);
  int w = 0;
  for (int i = head[cc[sz - 1]]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == cc[0] && !vis[i >> 1]) {
      w = e[i].cost;
      break;
    }
  }
  long long d0 = 0;
  for (int i = 0; i < sz; i++) {
    pos = 0, md = -1LL;
    Dfs(cc[i], 0, cc[i]);
    maxd[i] = std::exchange(md, -1LL);
    dep[pos] = 0, Dfs(pos, 0, cc[i]);
    checkmax(d0, md);
  }
  long long max = maxd[0];
  for (int i = 1; i < sz; i++) {
    pree[i] = std::max(pree[i - 1], maxd[i] + sum[i] + max);
    checkmax(max, maxd[i] - sum[i]);
  }
  max = maxd[sz - 1] + sum[sz - 1];
  for (int i = sz - 2; i >= 0; i--) {
    suff[i] = std::max(suff[i + 1], maxd[i] - sum[i] + max);
    checkmax(max, maxd[i] + sum[i]);
  }
  pre[0] = maxd[0];
  for (int i = 1; i < sz; i++) pre[i] = std::max(pre[i - 1], maxd[i] + sum[i]);
  suf[sz - 1] = maxd[sz - 1];
  for (int i = sz - 2; i >= 0; i--)
    suf[i] = std::max(suf[i + 1], maxd[i] + sum[sz - 1] - sum[i]);
  long long ans = pree[sz - 1];
  for (int i = 0; i + 1 < sz; i++)
    checkmin(ans, std::max({pree[i], suff[i + 1], pre[i] + suf[i + 1] + w}));
  checkmax(ans, d0);
  std::cout << ans;
  return 0;
}