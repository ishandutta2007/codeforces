// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back

namespace IO {
  const int SIZE = 1 << 21;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  char getc() {
    return getchar();
    //return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
  }
  int read() {
    int x = 0, f = 0;
    char ch = getc();
    while (!isdigit(ch)) f |= ch == '-', ch = getc();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getc();
    return f ? -x : x;
  }
  template<typename T> void print(T x) {
    if (x < 0) *O++ = '-', x = -x;
    if (x > 9) print(x / 10);
    *O++ = char(x % 10 + '0');
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 100005;
const int mod = 1e9 + 7;

int minp[10000001], pr[1000005], id[10000001], len;
bool vis[10000001];
void sieve(int n) {
  minp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pr[++len] = i, id[i] = len;
      minp[i] = i;
    }
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      minp[pr[j] * i] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

vector<int> adj[N];
int a[N], n, q;

struct Bit1 {
  int mul[25];
  void init() {
    for (int i = 1; i < 25; i++) mul[i] = 1;
  }
  void add(int x, int dlt) {
    while (x < 25) {
      mul[x] = 1ll * mul[x] * dlt % mod;
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 1;
    while (x > 0) {
      ret = 1ll * ret * mul[x] % mod;
      x ^= x & -x;
    }
    return ret;
  }
  int qry(int l, int r) {
    if (l > r) return 0;
    else return 1ll * qry(r) * qpow(qry(l - 1)) % mod;
  }
} mbit[700005];

struct Bit2 {
  int c[25];
  void add(int x, int dlt) {
    while (x < 25) {
      c[x] += dlt;
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 0;
    while (x > 0) {
      ret = (ret + c[x]) % mod;
      x ^= x & -x;
    }
    return ret;
  }
  int qry(int l, int r) {
    if (l > r) return 0;
    else return (qry(r) - qry(l - 1) + mod) % mod;
  }
} abit[700005];

struct node {
  int x, y, w;
} qry[N];
int ans[N];

int dep[N], f[N][20];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  f[u][0] = fa;
  for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) if (f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}

vector<pii> qwq[N];

void make(int x, int dlt) {
  while (x > 1) {
    int p = minp[x], mp = 1, zs = 0;
    while (minp[x] == p) {
      zs++;
      mp *= p, x /= minp[x];
    }
    if (dlt == 1) mbit[id[p]].add(zs, mp), abit[id[p]].add(zs, 1);
    else mbit[id[p]].add(zs, qpow(mp)), abit[id[p]].add(zs, -1);
  }
}
void dfs2(int u, int fa) {
  //printf("dfs2 %d\n", u);
  make(a[u], 1);
  //printf("make %d ok!\n", u);
  for (auto v: qwq[u]) {
    int w = v.fir, i = v.sec, cur = 1;
    while (w > 1) {
      int p = minp[w], mp = 1, zs = 0;
      while (minp[w] == p) {
        zs++;
        mp *= p, w /= minp[w];
      }
      cur = 1ll * cur * mbit[id[p]].qry(1, zs) % mod;
      int qaq = abit[id[p]].qry(zs + 1, 24);
      if (qaq) cur = 1ll * cur * qpow(mp, qaq) % mod;
    }
    //printf("u = %d, w = %d, i = %d\n", u, w, i);
    //printf("  cur = %d\n", cur);
    if (i < 0) ans[-i] = 1ll * ans[-i] * qpow(cur) % mod * qpow(cur) % mod;
    else ans[i] = 1ll * ans[i] * cur % mod;
  }
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs2(v, u);
  }
  make(a[u], -1);
}
signed main() {
  sieve(1e7);
  for (int i = 1; i <= len; i++) mbit[i].init();
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++) a[i] = read();
  dfs1(1, 0);
  q = read();
  for (int i = 1; i <= q; i++) {
    qry[i].x = read(), qry[i].y = read(), qry[i].w = read();
    int LCA = lca(qry[i].x, qry[i].y);
    //printf("LCA = %lld\n", LCA);
    qwq[LCA].push_back({qry[i].w, -i});
    qwq[qry[i].x].push_back({qry[i].w, i});
    qwq[qry[i].y].push_back({qry[i].w, i});
    ans[i] = gcd(qry[i].w, a[LCA]);
    //printf("ans[%d] = %lld\n", i, ans[i]);
  }
  dfs2(1, 0);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
} 

/*
3
1 2
2 3
100000 200000 40000
1
1 3 64000
*/