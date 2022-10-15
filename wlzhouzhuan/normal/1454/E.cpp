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

vector<int> adj[N];
int f[N], n;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int dep[N], FA[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  FA[u] = fa;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
  }
}
int Path[N], ban[N], len, ju, jv;
void getit() {
  len = 0;
  while (ju != jv) {
    if (dep[ju] > dep[jv]) Path[++len] = ju, ju = FA[ju];
    else Path[++len] = jv, jv = FA[jv];
  }
  Path[++len] = ju;
  rep(i, 1, len) ban[Path[i]] = 1;
}
int sz = 0;
ll ans = 0;
void dfs2(int u, int fa) {
  sz++;
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    dfs2(v, u); 
  }
}
void solve() {
  n = read();
  rep(i, 1, n) adj[i].clear(), ban[i] = 0, f[i] = i;
  rep(i, 1, n) {
    int u = read(), v = read();
    if (find(u) == find(v)) ju = u, jv = v;
    else adj[u].pb(v), adj[v].pb(u), f[find(u)] = find(v);
  }
  dfs1(1, 0), getit();
  ans = 0;
  rep(i, 1, len) {
    sz = 0, dfs2(Path[i], 0);
    ans += 1ll * sz * (sz - 1) / 2 + 1ll * (n - sz) * sz;
  }
  print(ans, '\n');
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}