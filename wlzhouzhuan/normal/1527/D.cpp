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
int n;

ll ans[N];

int dfn[N], sz[N], dtot;
void dfs1(int u, int fa) {
  dfn[u] = ++dtot, sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
  }
}
int In(int u, int v) {
  return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + sz[u];
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) adj[i].clear(), ans[i] = 0;
  ans[n] = ans[n + 1] = 0;
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }
  dtot = 0, dfs1(0, -1);
  ans[0] = ans[1] = 1ll * n * (n - 1) / 2;
  int son = -1;
  for (auto v: adj[0]) {
    ans[1] -= 1ll * sz[v] * (sz[v] - 1) / 2;
    if (In(v, 1)) son = v;
  }
  int x = 1, y = -1;
  for (int i = 1; i < n; i++) {
    int ok = 0;
    if (In(i, x)) ok = 1;
    if (y != -1 && In(i, y)) ok = 1;
    if (!ok) {
      if (In(x, i)) x = i;
      else if ((y == -1 && !In(son, i)) || (y != -1 && In(y, i))) y = i;
      else break;
    } 
    if (y == -1) ans[i + 1] = 1ll * sz[x] * (n - sz[son]);
    else ans[i + 1] = 1ll * sz[x] * sz[y];
  }
  for (int i = 0; i <= n; i++) {
    ans[i] -= ans[i + 1];
    print(ans[i], ' ');
  }
  putchar('\n');
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}