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

const int N = 505;
const int mod = 998244353;

vector<int> adj[N];
int dis[N][N];
int yes[N], pre[N], inq[N], n, m;

int main() {
  n = read(), m = read();
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    dis[u][v] = dis[v][u] = 1;
    adj[u].pb(v), adj[v].pb(u);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      for (int k = 1; k <= n; k++) yes[k] = 0, pre[k] = 0;
      for (int k = 1; k <= n; k++) {
        if (dis[i][k] + dis[k][j] == dis[i][j]) {
          yes[k] = 1;
          cnt++;
        }
      }
      if (cnt != dis[i][j] + 1) {
        printf("0 ");
        continue;
      }
      queue<int> q;
      for (int i = 1; i <= n; i++) {
        inq[i] = 0;
        if (yes[i]) {
          inq[i] = 1;
          q.push(i);
        }
      }
      int ans = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: adj[u]) {
          if (dis[u][i] + 1 == dis[v][i] && dis[u][j] + 1 == dis[v][j]) {
            pre[v]++;
            if (!inq[v]) inq[v] = 1, q.push(v);
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        if (!yes[i]) ans = 1ll * ans * pre[i] % mod;
      }
      printf("%d ", ans);
    }
    puts("");
  }
}