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

inline int pcnt(int x) {
  return __builtin_popcount(x);
}

const int mod = 1e9 + 7;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

struct Edge {
  int to, nxt, val;
} edge[112];
int head[112], tot;
void add(int u, int v, int w) {
  edge[++tot] = {v, head[u], w};
  head[u] = tot;
}

int fac[100005];
int x[56], y[56], z[56], tmpx[56], tmpy[56];
int n, m, lenx, leny;

int vis[112];
vector<int> L, R;

struct nod { int u, v, w; };
vector<pii> adj[112];
vector<nod> cir;

int id[112], V, E;
void getVE(int u, int fa) {
  vis[u] = vis[fa] + 1, V++;
  if (u <= lenx) id[u] = SZ(L), L.pb(u);
  else id[u] = SZ(R), R.pb(u);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (!vis[v]) {
      E++, getVE(v, u), adj[u].pb({v, edge[i].val});
    } else if (vis[v] > vis[u]) { //  
      E++, cir.pb({u, v, edge[i].val});
    }
  }
}

int f[56], g[56], h[56];

namespace sub1 {
  int dp[56][1 << 18];
  void main() {
    if (SZ(L) > SZ(R)) swap(L, R);
    int Lnum = SZ(L), Rnum = SZ(R);
    for (int i = 0; i <= Rnum; i++) memset(dp[i], 0, 4 * (1 << Lnum));
//    cerr<<"init ok!\n";
//    cerr<<"Lnum="<<Lnum<<",Rnum="<<Rnum<<'\n';
    dp[0][0] = 1;
    for (int i = 0; i < Rnum; i++) {
      for (int j = 0; j < (1 << Lnum); j++) {
        add(dp[i + 1][j], dp[i][j]);
//        cerr<<"Rnum="<<Rnum<<'\n';
//        cerr<<"in "<<i<<' '<<j<<'\n';
        for (int _ = head[R[i]]; _; _ = edge[_].nxt) {
          int v = edge[_].to, w = edge[_].val;
          if (j >> id[v] & 1) continue;
//          assert(id[v]<18);
//          cerr<<"~ "<<v<<":="<<id[v]<< " "<< j << '\n';
          add(dp[i + 1][j ^ 1 << id[v]], 1ll * dp[i][j] * w % mod); 
        }
//        cerr<<"out\n";
      }
    }
//    cerr<<"dp ok!\n";
    for (int i = 0; i < (1 << Lnum); i++)
      add(g[pcnt(i)], dp[Rnum][i]);
  }
}

namespace sub2 {
  int dp[112][2][56], tmp[2][56], ban[112], sz[112];
  void dfs(int u) {
    memset(dp[u][0], 0, 4 * (sz[u] + 1));
    memset(dp[u][1], 0, 4 * (sz[u] + 1));
    sz[u] = 1, dp[u][0][0] = 1;
    for (auto it: adj[u]) {
      int v = it.fir;
      dfs(v);
      memset(tmp[0], 0, 4 * (sz[u] + sz[v] + 1));
      memset(tmp[1], 0, 4 * (sz[u] + sz[v] + 1));
      for (int j = 0; j <= sz[u]; j++) {
        for (int k = 0; k <= sz[v]; k++) {
          add(tmp[0][j + k], 1ll * dp[u][0][j] * (dp[v][0][k] + dp[v][1][k]) % mod);
          if (!ban[u]) {
            add(tmp[1][j + k], 1ll * dp[u][1][j] * (dp[v][0][k] + dp[v][1][k]) % mod);
            if (!ban[v])
              add(tmp[1][j + k + 1], 1ll * dp[u][0][j] * dp[v][0][k] % mod * it.sec % mod);
          }
        }
      }
      memcpy(dp[u][0], tmp[0], 4 * (sz[u] + sz[v] + 1));
      memcpy(dp[u][1], tmp[1], 4 * (sz[u] + sz[v] + 1));
      sz[u] += sz[v];
    }
  }
  void main(int rt) {
    int len = SZ(cir);
    for (int i = 0; i < 1 << len; i++) {
      int coef = 1;
      memset(ban, 0, 4 * (lenx + leny + 1));
      for (int j = 0; j < len; j++) if (i >> j & 1) {
        if (ban[cir[j].u] || ban[cir[j].v]) {
          coef = 0;
          break;
        }
        coef = 1ll * coef * cir[j].w % mod;
        ban[cir[j].u] = ban[cir[j].v] = 1;
      }
      if (!coef) continue;
//      memset(dp[rt], 0, sizeof(dp[rt]));
      dfs(rt);
      for (int j = 0, c = pcnt(i); j + c <= m; j++)
        add(g[j + c], 1ll * coef * (dp[rt][0][j] + dp[rt][1][j]) % mod);
    }
  }
}

int main() {
  n = read(), m = read();
  fac[0] = 1; for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= m; i++) {
    x[i] = read(), y[i] = read(), z[i] = read() - 1;
    tmpx[i] = x[i], tmpy[i] = y[i];
  }
  sort(tmpx + 1, tmpx + m + 1), sort(tmpy + 1, tmpy + m + 1);
  lenx = unique(tmpx + 1, tmpx + m + 1) - tmpx - 1;
  leny = unique(tmpy + 1, tmpy + m + 1) - tmpy - 1;
  for (int i = 1; i <= m; i++) {
    x[i] = lower_bound(tmpx + 1, tmpx + lenx + 1, x[i]) - tmpx;
    y[i] = lower_bound(tmpy + 1, tmpy + leny + 1, y[i]) - tmpy;
    add(x[i], lenx + y[i], z[i]), add(lenx + y[i], x[i], z[i]);
  }
  f[0] = 1;
  for (int i = 1; i <= lenx + leny; i++) {
    if (!vis[i]) {
      for (int j = 1; j < 112; j++) adj[j].clear();
      V = 0, E = 0, L.clear(), R.clear(), cir.clear();
      memset(g, 0, 4 * (m + 1));
      getVE(i, 0);
//      printf("%d %d\n", V, E);
      if (V <= 2 * E / 3) sub1::main();
      else sub2::main(i);
      memset(h, 0, 4 * (m + 1));
      for (int j = 0; j <= m; j++) {
        for (int k = 0; j + k <= m; k++) {
          add(h[j + k], 1ll * f[j] * g[k] % mod);
        }
      }
      memcpy(f, h, 4 * (m + 1));
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++)
    add(ans, 1ll * f[i] * fac[n - i] % mod);
  print(ans, '\n');
  return 0;
}

/*
10000 40
1 14 523787872
1 13 858311801
1 12 566308144
1 11 134062538
1 10 717287030
1 9 388774482
1 8 141085571
1 7 840341897
1 6 129653263
1 5 302761193
1 4 201817391
1 3 4566861
1 2 674037291
1 1 621515810
9241 6446 790191211
2 1 697092196
3 1 954708810
4 1 873445240
5 1 996581432
6 1 645164111
7 1 647392589
8 1 855391519
9 1 471908435
10 1 954687655
11 1 838568919
12 1 735026507
13 1 627397646
14 1 84374206
2 11 407726639
5 12 67968818
9 11 793334111
4 11 582107187
10 5 715100921
12 13 217226706
8 2 989801769
6 11 717618231
12 14 628830250
3202 8376 969439411
6261 3110 842827187
9953 2197 148884440
*/