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

const int N = 1000005;
vector<int> adj[N];
int n, m, vis[N], f[N], col[N];

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(int u, int fa) {
  vis[u] = 1, col[u] = !col[fa];
  for (auto v: adj[u]) if (vis[v]) col[u] &= !col[v];
  for (auto v: adj[u]) if (!vis[v] && v != fa) {
    dfs(v, u);
  }
}
int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
      vis[i] = 0, f[i] = i;
      adj[i].clear(), col[i] = 0;
    }
    int comp = n;
    for (int i = 1; i <= m; i++) {
      int u = read(), v = read();
      if (find(u) != find(v)) comp--, f[find(u)] = find(v);
      adj[u].pb(v), adj[v].pb(u);
    }
    if (comp != 1) {
      puts("NO"); continue;
    }
    dfs(1, 0);
    int cnt = 0;
    puts("YES");
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (col[i]) ans.pb(i), cnt++;
    printf("%d\n", cnt);
    for (auto v: ans) printf("%d ", v);
    puts("");
  }
  return 0;
}