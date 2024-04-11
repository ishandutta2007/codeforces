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
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

const int N = 1000005;
struct Edge {
  int to, nxt;
} edge[N << 1];
int deg[N], head[N], tot = 1;
void add(int u, int v) {
  edge[++tot] = {v, head[u]};
  head[u] = tot;
}

int n;

int vis[N];
void dfs(int u) {
  for (int &i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (vis[i >> 1]) continue;
    vis[i >> 1] = 1 + (i & 1);
//    printf("vis[%d] = %d, v = %d\n", i >> 1, vis[i >> 1], v);
    dfs(v);
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int u = read(), v = read();
    deg[u]++, deg[300000 + v]++;
    add(u, v + 300000), add(v + 300000, u);
  }
  for (int i = 1; i <= 300000 + 300000; i++) if (deg[i] & 1) add(0, i), add(i, 0);
  for (int i = 1; i <= 300000; i++) dfs(i);
  for (int i = 1; i <= n; i++) {
//    printf("vis[%d] = %d\n", i, vis[i]);
    putchar("br"[vis[i] - 1]);
  }
  return 0;
}