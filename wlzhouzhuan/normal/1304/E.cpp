// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 100002;
vector <int> adj[N];
int n;

int f[N][20], dep[N];
void dfs(int u, int Fa) {
  dep[u] = dep[Fa] + 1, f[u][0] = Fa;
  for (rint i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (auto v: adj[u]) {
    if (v == Fa) continue;
    dfs(v, u);
  } 
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (rint i = 19; i >= 0; i--) {
    if (dep[u] - (1 << i) >= dep[v]) {
      u = f[u][i];
    }
  }
  if (u == v) return u;
  for (rint i = 19; i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i], v = f[v][i];
    }
  }
  return f[u][0];
}
int dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
  n = read();
  for (rint i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(1, 0);
  int q = read();
  while (q--) {
    int x = read(), y = read(), a = read(), b = read(), len = read();
    int dist1 = dist(a, b);
    int dist2 = min(dist(x, a) + dist(y, b), dist(x, b) + dist(y, a)) + 1;
    if (len >= dist1 && (len - dist1) % 2 == 0) puts("YES");
    else if (len >= dist2 && (len - dist2) % 2 == 0) puts("YES");
    else puts("NO");
  }
  return 0;
}