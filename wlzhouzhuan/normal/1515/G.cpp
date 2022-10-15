// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
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
#define SZ(x) (int(x.size()))
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

const int N = 200005;

struct Edge { int to, nxt, val; } edge[N];
int head[N], etot;
void add(int u, int v, int w) {
  edge[++etot] = {v, head[u], w}, head[u] = etot;
}

int n, m, q;

int dfn[N], low[N], dtot;
bool vis[N];
stack<int> stk;
int be[N], btot;
void tarjan(int u) {
  dfn[u] = low[u] = ++dtot, vis[u] = 1, stk.push(u);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    int y; ++btot;
    do {
      y = stk.top(); stk.pop();
      be[y] = btot, vis[y] = 0;
    } while (y != u);
  }
}

ll dis[N], G[N], g = 0;
void dfs1(int u, int fa) {
  vis[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (be[v] != be[u]) continue;
    if (!vis[v]) {
      dis[v] = dis[u] + edge[i].val;
      dfs1(v, u);
    } else {
      g = __gcd(g, dis[u] - dis[v] + edge[i].val);
    }
  }
}

int main() {
  n = read(), m = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    add(u, v, w);
  }
  rep(i, 1, n) {
    if (!dfn[i]) tarjan(i);
  }
  memset(vis, 0, sizeof(vis));
  rep(i, 1, n) {
    if (!vis[i]) {
      g = 0;
      dfs1(i, 0);
      G[be[i]] = g;
    }
  }
  q = read();
  while (q--) {
    int u = read(), s = read(), t = read();
    if ((t - s) % __gcd(G[be[u]], (ll)t) == 0) puts("YES");
    else puts("NO");
  }
  return 0;
}