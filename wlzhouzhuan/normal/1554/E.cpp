// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 100005;
const int mod = 998244353;

int pr[N], len;
bool vis[N];
void xxs(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i;
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}

vector<int> adj[N];
int f[N], n;

int sz[N], k;
int dfs(int u, int fa) {
  sz[u] = 0;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    if (!dfs(v, u)) return 0;
    sz[u] += sz[v];
  }
  if (sz[u] % k == 0) { sz[u] = 1; return 1; }
  if ((sz[u] + 1) % k == 0) { sz[u] = 0; return 1; }
  return 0;
}

void solve() {
  n = read();
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  f[1] = 1;
  rep(i, 1, n - 1) f[1] = 2 * f[1] % mod;
  rep(i, 2, n) {
    f[i] = 0;
    if ((n - 1) % i == 0)
      k = i, f[i] = dfs(1, 0);
  }
  rep(i, 1, len) {
    if (pr[i] > n) break;
    rep(j, 1, n / pr[i])
      f[j] = (f[j] + mod - f[j * pr[i]]) % mod;
  }
  rep(i, 1, n) print(f[i], " \n"[i == n]);
}

int main() {
  xxs(1e5);
  int T = read();
  while (T--) solve();
  return 0;
}

/*
1
5
1 2
2 3
3 4
4 5
*/