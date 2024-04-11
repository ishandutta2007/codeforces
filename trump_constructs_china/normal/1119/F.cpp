#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <set>
#include <vector>
int k, deg[250001], cur[250001];
std::vector<std::pair<int, int>> g[250001];
std::vector<int> D[250001], a[250001];
bool vis[250001];
std::multiset<long long> s[250001];
long long sum[250001], dp[250001][2];
void Insert(int p, long long x) {
  s[p].emplace(x);
  sum[p] += x;
}
void Erase(int p, long long x) {
  s[p].erase(s[p].find(x));
  sum[p] -= x;
}
void Dfs(int u) {
  vis[u] = true;
  while (cur[u] < deg[u] && deg[g[u][cur[u]].first] <= k) cur[u]++;
  int lim = deg[u] - k, l0 = std::max(lim, 0), l1 = std::max(lim - 1, 0);
  while (static_cast<int>(s[u].size()) > l0) Erase(u, *s[u].rbegin());
  long long d = 0LL;
  std::vector<long long> ad, dl;
  for (int i = cur[u]; i < deg[u]; i++) {
    int v = g[u][i].first, e = g[u][i].second;
    if (vis[v]) continue;
    Dfs(v);
    if (dp[v][1] + e <= dp[v][0]) {
      d += dp[v][1] + e;
      lim--;
      continue;
    }
    d += dp[v][0];
    long long delta = dp[v][1] + e - dp[v][0];
    Insert(u, delta);
    ad.emplace_back(delta);
  }
  l0 = std::max(lim, 0);
  l1 = std::max(lim - 1, 0);
  while (static_cast<int>(s[u].size()) > l0) {
    long long t = *s[u].rbegin();
    dl.emplace_back(t);
    Erase(u, t);
  }
  dp[u][0] = d + sum[u];
  while (static_cast<int>(s[u].size()) > l1) {
    long long t = *s[u].rbegin();
    dl.emplace_back(t);
    Erase(u, t);
  }
  dp[u][1] = d + sum[u];
  for (auto &&i : dl) Insert(u, i);
  for (auto &&i : ad) Erase(u, i);
}
std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
  for (int i = 0; i < N - 1; i++) {
    g[U[i]].emplace_back(V[i], W[i]);
    g[V[i]].emplace_back(U[i], W[i]);
    deg[U[i]]++;
    deg[V[i]]++;
  }
  for (int i = 1; i <= N; i++)
    std::sort(g[i].begin(), g[i].end(),
              [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
                  -> bool { return deg[lhs.first] < deg[rhs.first]; });
  for (int i = 1; i <= N; i++) {
    D[deg[i]].emplace_back(i);
    for (int j = 1; j < deg[i]; j++) a[j].emplace_back(i);
  }
  std::vector<long long> ans(N);
  ans[0] = std::accumulate(W.begin(), W.end(), 0LL);
  for (k = 1; k < N; k++) {
    for (auto &&i : D[k]) {
      vis[i] = true;
      for (auto &&j : g[i])
        if (!vis[j.first]) Insert(j.first, j.second);
    }
    for (auto &&i : a[k])
      if (!vis[i]) {
        Dfs(i);
        ans[k] += dp[i][0];
      }
    for (auto &&i : a[k]) vis[i] = false;
  }
  return ans;
}
int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) scanf("%d %d %d", &U[i], &V[i], &W[i]);
  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) printf(" ");
    printf("%lld", closure_costs[i]);
  }
  return 0;
}