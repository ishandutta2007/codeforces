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

#define size SIZE

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

const int N = 400005;

vector<int> adj[N], E[N];
int n, m;

int dfn[N], low[N], dtot;
int be[N], size[N], ctot, vis[N]; stack<int> stk;

void tarjan(int u) {
  dfn[u] = low[u] = ++dtot, vis[u] = 1, stk.push(u);
  for (auto v: adj[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    int y; ++ctot; size[ctot] = 0;
    do {
      y = stk.top(); stk.pop();
      size[ctot]++;
      vis[y] = 0; be[y] = ctot;
    } while (y != u);
  }
}
int type[N], deg[N];
bool canvis[N];
void dfs_topo(int u) {
  canvis[u] = 1;
  for (auto v: E[u]) {
    if (!canvis[v]) dfs_topo(v);
  }
}
void topo_sort() {
  for (int i = 1; i <= ctot; i++) type[i] = 0, canvis[i] = 0;
  canvis[be[1]] = 1, dfs_topo(be[1]);
  queue<int> q;
  for (int i = 1; i <= ctot; i++) {
    if (size[i] > 1 && canvis[i]) type[i] = -1;
    if (deg[i] == 0) {
      if (i != be[1]) type[i] = 0;
      else if (type[i] != -1) type[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
//    printf("in queue %d\n", u);
    for (auto v: E[u]) {
      if (type[u] == -1 || type[v] == -1) type[v] = -1;
      else type[v] = min(2, type[u] + type[v]);
      if (--deg[v] == 0) {
        if (v == be[1] && type[v] != -1) type[v] = 1; 
        q.push(v);
      }
    }
  }
}

void solve() {
  dtot = ctot = 0;
  n = read(), m = read();
  rep(i, 1, n) adj[i].clear(), dfn[i] = low[i] = vis[i] = 0, E[i].clear(), deg[i] = 0;
  rep(i, 1, m) {
    int u = read(), v = read();
    adj[u].pb(v);
  }
  rep(i, 1, n) if (!dfn[i]) tarjan(i);
//  rep(i, 1, n) printf("be[%d] = %d\n", i, be[i]);
  rep(i, 1, n) {
    for (auto j: adj[i]) {
      if (be[i] != be[j])
        E[be[i]].pb(be[j]), deg[be[j]]++;
      if (i == j)
        size[be[i]]++;
    }
  }
  topo_sort();
//  printf("type[%d] = %d\n", be[1], type[be[1]]);
  rep(i, 1, n) {
    int t = type[be[i]];
    if (!canvis[be[i]]) print(0, ' ');
    else print(t, ' ');
  }
  putchar('\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
} 

/*
1
6 4
1 2
3 2
5 1
6 2
*/

/*
1
10 1
1 1 
*/

/*
1
10 15
1 2
2 3
2 6
3 4
4 5
5 3
11 1
10 11
12 10
9 10
7 8
8 9
9 7
10 1
7 1
*/