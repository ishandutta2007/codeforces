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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
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
vector<int> adj[N], to[N];
int lst[N], id[N], vis[N], n, B;

int main() {
  for (int T = read(); T; T--) {
    n = read(), B = 350;
    map<int, int> Map;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      adj[i].resize(read());
      for (auto &v: adj[i]) {
        v = read();
        if (!Map[v]) Map[v] = ++cnt;
        v = Map[v];
      }
      sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i <= cnt; i++) to[i].clear(), vis[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (auto v: adj[i]) {
        to[v].pb(i);
      }
    }
    int ok = 0;
    for (int i = 1; i <= cnt; i++) lst[i] = id[i] = 0;
    for (int i = 1; i <= cnt; i++) {
      for (auto v: to[i]) {
        if (adj[v].size() > B) continue; 
        for (int j = 0; j < adj[v].size() && adj[v][j] < i; j++) {
          int u = adj[v][j];
          if (lst[u] == i) {
            printf("%d %d\n", id[u], v);
            ok = 1;
            break;
          }
          lst[u] = i, id[u] = v;
        }
        if (ok) break;
      }
      if (ok) break;
    }
    if (ok) continue; 
    for (int i = 1; i <= n; i++) if (adj[i].size() > B) {
      for (auto v: adj[i]) vis[v] = 1;
      for (int j = 1; j <= n; j++) if (i != j) {
        int cnt = 0;
        for (auto v: adj[j]) cnt += vis[v];
        if (cnt >= 2) {
          printf("%d %d\n", i, j);
          ok = 1;
          break;
        }
      }
      for (auto v: adj[i]) vis[v] = 0;
      if (ok) break;
    }
    if (ok) continue;
    puts("-1");
  }
  return 0;
}