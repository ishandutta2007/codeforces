// Author: wlzhouzhuan
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
const int N = 200005;
vector<int> adj[N];
int fib[55], n;

int vis[N], FA[N], sz[N], tag;
void dfs(int u, int fa, int id) {
  sz[u] = 1, FA[u] = fa;
  for (auto v: adj[u]) {
    if (v == fa || vis[v]) continue;
    dfs(v, u, id);
    sz[u] += sz[v];
  }
  if (sz[u] == fib[id - 1] || sz[u] == fib[id - 2]) {
    tag = u;
  }
}
bool check(int rt, int id) {
  if (id <= 1) return 1;
  tag = 0;
  dfs(rt, 0, id);
//  printf("check rt = %d, id = %d, t = %d\n", rt, id, tag);
  int t = tag, fa = FA[t], id1, id2;
  if (!tag) return 0;
  if (sz[t] == fib[id - 1]) id1 = id - 1, id2 = id - 2;
  else id1 = id - 2, id2 = id - 1;
  vis[fa] = 1;
  if (!check(t, id1)) return 0;
  vis[fa] = 0;
  vis[t] = 1;
  if (!check(fa, id2)) return 0;
  vis[t] = 0;
  return 1; 
}

int main() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= 30; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int id = 0;
  for (int i = 1; i <= 30; i++) {
    if (fib[i] == n) {
      id = i;
      break;
    }
  }
  if (!id) return puts("NO"), 0;
  puts(check(1, id) ? "YES" : "NO");
  return 0;
}