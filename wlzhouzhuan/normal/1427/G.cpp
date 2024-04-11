// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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

const int N = 205;
const int inf = 1e9;

int a[N][N], tmp[N * N], len;
int tag[N][N], n, S, T;
int id(int x, int y) {
  return (x - 1) * n + y;
}

struct Edge {
  int to, nxt, cap;
} edge[N * N << 3];
int head[N * N], cur[N * N], tot = 1;
void add(int u, int v, int cap) {
  edge[++tot] = {v, head[u], cap};
  head[u] = tot;
}
void addedge(int u, int v, int cap1, int cap2) {
  add(u, v, cap1), add(v, u, cap2);
}

int dis[N * N];
bool bfs(int S, int T) {
  for (int i = 1; i <= n * n + 2; i++) dis[i] = -1, cur[i] = head[i]; 
  queue<int> q; q.push(S), dis[S] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, cap = edge[i].cap;
      if (dis[v] == -1 && cap) {
        dis[v] = dis[u] + 1;
        if (v == T) return 1; 
        q.push(v);
      } 
    }
  }
  return 0;
}
int dfs(int u, int T, int ans) {
  if (u == T) return ans;
  int over = 0;
  for (int &i = cur[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, cap = edge[i].cap;
    if (dis[v] == dis[u] + 1 && cap) {
      int t = dfs(v, T, min(ans, cap));
      over += t, ans -= t;
      edge[i].cap -= t, edge[i ^ 1].cap += t;
      if (!t) dis[v] = -1;
      if (!ans) break;
    }
  }
  return over;
}
int Dinic(int S, int T) {
  int res = 0;
  while (bfs(S, T)) res += dfs(S, T, 1e9);
  return res;
}

int main() {
  n = read(), S = n * n + 1, T = S + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = read();
      if (a[i][j] > 0) tmp[++len] = a[i][j];
    }
  }
  sort(tmp + 1, tmp + len + 1), len = unique(tmp + 1, tmp + len + 1) - (tmp + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == -1) continue;
      if (a[i][j] > 0) addedge(id(i, j), T, inf, 0), tag[i][j] = tot;
      if (i > 1 && a[i - 1][j] != -1) addedge(id(i, j), id(i - 1, j), 1, 1);
      if (j > 1 && a[i][j - 1] != -1) addedge(id(i, j), id(i, j - 1), 1, 1); 
    }
  }
  ll ans = 0;
  int flow = 0;
  for (int t = 1; t < len; t++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == tmp[t]) {
          int k = tag[i][j];
          flow -= edge[k].cap;
          edge[k].cap = edge[k ^ 1].cap = 0, Dinic(id(i, j), S);
          addedge(S, id(i, j), inf, 0);
        }
      }
    }
    flow += Dinic(S, T);
    ans += 1ll * flow * (tmp[t + 1] - tmp[t]);
  }
  printf("%lld\n", ans);
  return 0;
}