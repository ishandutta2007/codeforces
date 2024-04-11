// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast", "inline")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

const int N = 200005;
vector<int> adj[N];
ll va[N];
int n, m;

void dfs(int u, int fa) {
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    va[u] -= va[v];
  }
}

ll jiba[2];
int vis[N], dep[N], dad[N], ji, ok;
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1, dad[u] = fa;
  vis[u] = 1;
  jiba[dep[u] & 1] += va[u];
  for (auto v: adj[u]) {
    if (v == fa) continue;
    if (!vis[v]) dfs1(v, u);
    else if (dep[v] < dep[u]) {
      if ((dep[u] - dep[v]) % 2 == 0) ji = 1;
    }
  }
}

void solve() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;
  jiba[0] = jiba[1] = 0;
  for (int i = 1; i <= n; i++) va[i] = read();
  for (int i = 1; i <= n; i++) va[i] -= read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  if (m >= n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) ret = (ret + va[i]) % 2;
    ji = 0, ok = 1;
    dfs1(1, 0);
//    cerr << "ji =" << ji << ", ok = " << ok << '\n';
    if (ret) puts("NO");
    else if (ji || jiba[0] == jiba[1]) puts("YES");
    else puts("NO"); 
  } else {
    dfs(1, 0);
    if (va[1] == 0) puts("YES");
    else puts("NO");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}