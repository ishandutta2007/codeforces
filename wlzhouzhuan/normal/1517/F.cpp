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

const int N = 305;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

vector<int> adj[N];

// f[u][dep]: , dep
// g[u][dep]: dep 
int f[N][N], g[N][N], tmpf[N], tmpg[N], maxd[N];
int n, r;

void dfs(int u, int fa) {
  f[u][0] = 1, g[u][0] = 1, maxd[u] = 0;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    memset(tmpf, 0, 4 * (max(maxd[u], maxd[v] + 1) + 1));
    memset(tmpg, 0, 4 * (max(maxd[u], maxd[v] + 1) + 1));
    rep(i, 0, maxd[u]) {
      rep(j, 0, maxd[v]) {
        add(tmpf[min(i, j + 1)], 1ll * f[u][i] * f[v][j] % mod);
        if (i + j + 1 <= r) add(tmpf[i], 1ll * f[u][i] * g[v][j] % mod);
        else add(tmpg[j + 1], 1ll * f[u][i] * g[v][j] % mod);
        if (i + j + 1 <= r) add(tmpf[j + 1], 1ll * g[u][i] * f[v][j] % mod);
        else add(tmpg[i], 1ll * g[u][i] * f[v][j] % mod);
        add(tmpg[max(i, j + 1)], 1ll * g[u][i] * g[v][j] % mod);
      }
    }
    maxd[u] = max(maxd[u], maxd[v] + 1);
    rep(i, 0, maxd[u]) f[u][i] = tmpf[i], g[u][i] = tmpg[i];
  }
}

int main() {
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  int lst = 0, ans = 0;
  rep(i, 1, n) { // r = i ()
    r = i;
    memset(f, 0, 4 * (n + 1));
    memset(g, 0, 4 * (n + 1));
    dfs(1, 0);
    int now = 0;
    rep(j, 0, n) add(now, f[1][j]);
//    printf("i = %d, now = %d\n", i, now);
    ans = (ans + 1ll * (now - lst + mod) * (i - 1)) % mod;
    lst = now;
  }
  // r = -1: -1; r = n: n
  ans = (ans - 1 + n) % mod;
  printf("%d\n", 1ll * ans * qpow(inv2, n) % mod); 
  return 0;
}