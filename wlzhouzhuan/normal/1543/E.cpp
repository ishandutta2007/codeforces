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

const int N = 65536;
vector<int> adj[N];
int p[N], Q[N], ans[N], dep[N];
int n, node;

void get() {
  memset(dep, -1, 4 << n);
  memset(p, 0, 4 << n);
  queue<int> q;
  q.push(0), dep[0] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u == 0) {
      for (int i = 0; i < n; i++) {
        dep[adj[u][i]] = dep[u] + 1;
        p[adj[u][i]] |= 1 << i;
        q.push(adj[u][i]);
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (!~dep[adj[u][i]])
          dep[adj[u][i]] = dep[u] + 1, q.push(adj[u][i]);
        if (dep[adj[u][i]] == dep[u] + 1)
          p[adj[u][i]] |= p[u];
      }
    }
  }
  memcpy(Q, p, 4 << n);
  memset(p, 0, 4 << n);
  for (int i = 0; i < node; i++) p[Q[i]] = i;
}

void solve() {
  n = read(), node = 1 << n;
  memset(ans, 0, 4 << n);
  for (int i = 0; i < node; i++) adj[i].clear();
  for (int i = 0; i < n * node / 2; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  get();
  for (int i = 0; i < node; i++) printf("%d ", p[i]); puts("");
  for (int i = 0; i < node; i++) {
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        ans[p[i]] ^= j;
      }
    }
  }
  if (n & (n - 1)) {
    puts("-1");
  } else {
    for (int i = 0; i < node; i++) printf("%d ", ans[i]); puts("");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}