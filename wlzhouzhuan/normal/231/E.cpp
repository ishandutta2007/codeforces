//  /jy 
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 100005;
const ll mod = 1e9 + 7;

struct Edge {
  int to, nxt;
  Edge (int to = 0, int nxt = 0):
    to(to), nxt(nxt) {}
} edge[N << 1];
int head[N], tot;

void add(int u, int v) {
  edge[++tot] = Edge(v, head[u]);
  head[u] = tot;
}

int dfn[N], low[N], ff;
int vis[N], be[N], sz[N], col;
stack <int> st;
void tarjan(int u, int lst) {
  dfn[u] = low[u] = ++ff;
  vis[u] = 1, st.push(u);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (i == (lst ^ 1)) continue;
    if (!dfn[v]) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
    }
    else if (vis[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    int y; col++;
    while (y = st.top()) {
      vis[y] = 0, be[y] = col, sz[col]++, st.pop();
      if (y == u) break; 
    }
  }
}

int Q[N][2];
int n, m; 

int f[N][20], dep[N], w[N];
void dfs(int u, int fa) {
  f[u][0] = fa;
  for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dep[v] = dep[u] + 1, w[v] += w[u];
    dfs(v, u);
  }
}

void rebuild() {
  fill(head + 1, head + n + 1, 0); tot = 1;
  for (int i = 1; i <= m; i++) {
    int u = be[Q[i][0]], v = be[Q[i][1]];
    if (u == v) continue;
    add(u, v); add(v, u);
  }
  for (int i = 1; i <= col; i++) {
    if (sz[i] > 1) w[i] = 1;
    else w[i] = 0;
  }
  dep[be[1]] = 1; dfs(be[1], 0);
  #ifdef debug
  for (int i = 1; i <= col; i++) {
    printf("w[%d] = %d\n", i, w[i]);
  }
  #endif
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[u] - (1 << i) >= dep[v])
      u = f[u][i];
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (f[u][i] != f[v][i])
      u = f[u][i], v = f[v][i];
  }
  return f[u][0];
}
ll pw2[N];
ll qpow(ll k) { return pw2[k]; } 
int main() {
  scanf("%d%d", &n, &m); tot = 1;
  pw2[0] = 1; for (int i = 1; i <= n; i++) pw2[i] = pw2[i - 1] * 2LL % mod;

  for (int i = 1; i <= m; i++) { 
    int u, v; read(u, v);
    Q[i][0] = u, Q[i][1] = v;
    add(u, v); add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }

  #ifdef debug
  for (int i = 1; i <= col; i++) {
    printf("     block %d\n     ", i);
    for (int j = 1; j <= n; j++)
      if (be[j] == i)
        printf("%d ", j);
    putchar('\n');
  }
  #endif

  rebuild();
  int q; read(q);
  while (q--) {
    int u, v; read(u, v);
    u = be[u], v = be[v];
    if (u == v) { puts("2"); continue; }
    int fa = lca(u, v);
    printf("%lld\n", qpow(w[u] + w[v] - w[fa] - w[f[fa][0]]));
  }
  return 0;
}