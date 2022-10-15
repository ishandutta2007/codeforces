#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t, n, m, dfn[400001], low[400001], tot, s[400001], top, col[400001], c,
    dp[400001], ind[400001];
vector<int> g[400001], g2[400001], g3[400001];
vector<pair<int, int>> e;
bool vis[400001], lp[400001], rc[400001], infi[400001];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline void ckmin(int &x, int y) {
  if (x > y) x = y;
}
void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u;
  vis[u] = true;
  for (auto &&v : g[u])
    if (!dfn[v]) {
      tarjan(v);
      ckmin(low[u], low[v]);
    } else if (vis[v]) {
      ckmin(low[u], dfn[v]);
    }
  if (low[u] == dfn[u]) {
    col[u] = ++c;
    vis[u] = false;
    int sz = 1;
    while (s[top] != u) {
      col[s[top]] = c;
      vis[s[top--]] = false;
      sz++;
    }
    top--;
    if (sz > 1) infi[c] = true;
  }
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
      int u = read(), v = read();
      if (u == v) {
        lp[u] = true;
      } else {
        e.emplace_back(u, v);
        g[u].emplace_back(v);
      }
    }
    queue<int> q;
    q.emplace(1);
    rc[1] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &&v : g[u]) {
        if (rc[v]) continue;
        q.emplace(v);
        rc[v] = true;
      }
    }
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i);
    for (auto &&i : e) {
      int u = i.first, v = i.second;
      if (col[u] != col[v]) g2[col[u]].emplace_back(col[v]);
    }
    for (int i = 1; i <= n; i++)
      if (lp[i] && rc[i]) infi[col[i]] = true;
    for (int i = 1; i <= n; i++)
      if (!rc[i] && infi[col[i]]) infi[col[i]] = false;
    for (int i = 1; i <= c; i++)
      if (infi[i]) q.emplace(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &&v : g2[u]) {
        if (infi[v]) continue;
        q.emplace(v);
        infi[v] = true;
      }
    }
    for (auto &&i : e) {
      int u = i.first, v = i.second;
      if (rc[u] && col[u] != col[v]) {
        g3[col[u]].emplace_back(col[v]);
        ind[col[v]]++;
      }
    }
    dp[col[1]] = 1;
    q.emplace(col[1]);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &&v : g3[u]) {
        dp[v] += dp[u];
        if (!--ind[v]) q.emplace(v);
      }
    }
    for (int i = 1; i <= n; i++)
      if (!rc[i])
        printf("0%c", " \n"[i == n]);
      else if (infi[col[i]])
        printf("-1%c", " \n"[i == n]);
      else if (dp[col[i]] == 1)
        printf("1%c", " \n"[i == n]);
      else
        printf("2%c", " \n"[i == n]);
    memset(dfn + 1, 0, 4 * n);
    memset(low + 1, 0, 4 * n);
    tot = top = c = 0;
    memset(s + 1, 0, 4 * n);
    memset(col + 1, 0, 4 * n);
    memset(dp + 1, 0, 4 * n);
    memset(ind + 1, 0, 4 * n);
    for (int i = 1; i <= n; i++) {
      vector<int>().swap(g[i]);
      vector<int>().swap(g2[i]);
      vector<int>().swap(g3[i]);
    }
    vector<pair<int, int>>().swap(e);
    memset(vis + 1, false, n);
    memset(lp + 1, false, n);
    memset(rc + 1, false, n);
    memset(infi + 1, false, n);
  }
  return 0;
}