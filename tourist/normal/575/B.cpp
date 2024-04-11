#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

inline int pw(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 200010;

vector < pair <int, int> > g[N];

int de[N];
int T, tin[N], tout[N];
int kw, w[N];
int pv[N], pr[N][22];

void dfs(int v) {
  w[kw++] = v;
  tin[v] = ++T;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (u == pv[v]) {
      continue;
    }
    pv[u] = v;
    de[u] = de[v] + 1;
    dfs(u);
  }
  tout[v] = ++T;
}

bool anc(int x, int y) {
  return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y) {
  if (anc(x, y)) return x;
  for (int j = 19; j >= 0; j--)
    if (!anc(pr[x][j], y)) x = pr[x][j];
  return pv[x];
}

int up[N], down[N];

void sums(int v) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (u == pv[v]) {
      continue;
    }
    sums(u);
    up[v] += up[u];
    down[v] += down[u];
  }
}

int ans;

void calc(int v) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (u == pv[v]) {
      continue;
    }
    int dir = g[v][j].second;
    if (dir == 1) {
      add(ans, pw(2, -up[u]));
      add(ans, md - 1);
    }
    if (dir == -1) {
      add(ans, pw(2, -down[u]));
      add(ans, md - 1);
    }
    calc(u);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int foo, bar, qwe;
    scanf("%d %d %d", &foo, &bar, &qwe);
    foo--; bar--;
    g[foo].push_back(make_pair(bar, qwe));
    g[bar].push_back(make_pair(foo, -qwe));
  }
  int root = 0;
  pv[root] = root;
  de[root] = 0;
  T = 0;
  kw = 0;
  dfs(root);
  for (int i = 0; i < n; i++) pr[i][0] = pv[i];
  for (int j = 1; j < 20; j++)
    for (int i = 0; i < n; i++) pr[i][j] = pr[pr[i][j - 1]][j - 1];
  for (int i = 0; i < n; i++) up[i] = down[i] = 0;
  int tt;
  scanf("%d", &tt);
  int cur = 0;
  while (tt--) {
    int nxt;
    scanf("%d", &nxt);
    nxt--;
    int z = lca(cur, nxt);
    up[cur]--;
    up[z]++;
    down[z]++;
    down[nxt]--;
    cur = nxt;
  }
  sums(root);
  ans = 0;
  calc(root);
  printf("%d\n", ans);
  return 0;
}