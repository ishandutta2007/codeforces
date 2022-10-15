// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 300005;
struct Edge {
  int to, nxt, val;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int w) {
  edge[++tot] = {v, head[u], w};
  head[u] = tot;
}
int a[N], n, q;

int dep[N];
int F[N][19], anc[N][19], f[N], g[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1, f[u] = a[u];
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs1(v, u);
    f[u] += max(0ll, f[v] - 2 * edge[i].val);
  }
}
void dfs2(int u, int fa) {
  for (int j = 1; j < 19; j++) {
    anc[u][j] = anc[anc[u][j - 1]][j - 1];
    F[u][j] = F[u][j - 1] + F[anc[u][j - 1]][j - 1] - f[anc[u][j - 1]];
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    F[v][0] = f[u] + f[v] - edge[i].val - max(0ll, f[v] - 2 * edge[i].val);
    anc[v][0] = u;
    g[v] = max(0ll, g[u] + f[u] - max(0ll, f[v] - 2 * edge[i].val) - 2 * edge[i].val);
    dfs2(v, u);
  }
}
int query(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ans = 0, _u = u, _v = v;
  for (int i = 18; i >= 0; i--) {
    if (dep[anc[u][i]] >= dep[v]) {
      ans += F[u][i] - f[u];
      u = anc[u][i];
    }
  }
  if (u == v) return ans + f[_u] + g[u];
  for (int i = 18; i >= 0; i--) {
    if (anc[u][i] && anc[u][i] != anc[v][i]) {
      ans += F[u][i] - f[u] + F[v][i] - f[v];
      u = anc[u][i], v = anc[v][i];
    }
  } 
  return ans + F[u][0] - f[u] + F[v][0] - f[v] - f[anc[u][0]] + f[_u] + f[_v] + g[anc[u][0]];
}
signed main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), w = read();
    add(u, v, w), add(v, u, w);
  }
  dfs1(1, 0), dfs2(1, 0);
  while (q--) {
    int u = read(), v = read();
    print(query(u, v), '\n');
  }
  return 0;
}