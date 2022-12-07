#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
typedef long long ll;
 
struct edge {
  int to, w;
};
 
const int N = (int) (1e5) + 7;
const int MOD = (int)(1e9) + 7;
 
vector <edge> g[N];
 
int u[N];
int par[N];
edge w[N];
int dp[N], tin[N];
 
int tt = 0;
 
const int M = (1 << 18);
 
int ans[M];
 
auto svert = [] (int *ans, bool i, int MOD) {
  for (int len = 2; len <= M; len *= 2) {
    for (int j = 0; j < M; j += len) {
      for (int k = 0; k < len / 2; k++) {
        int a = ans[j + k], b = ans[j + k + len / 2];
        ans[j + k] = (a + b) % MOD;
        ans[j + k + len / 2] = (a - b + MOD) % MOD;
      }
    }
  }
  if (i) {
    int inv = 1;
    for (int x = 0; x < 18; x++) {
      inv = (inv * (ll) ((MOD + 1) / 2)) % MOD;
    }
    for (int i = 0; i < M; i++) {
      ans[i] = (ans[i] * (ll) inv) % MOD;
    }
  }
};
 
auto mul = [] (int *x, int *y, int MOD) {
  svert(x, false, MOD);
  svert(y, false, MOD);
  for (int i = 0; i < M; i++) {
    x[i] = (x[i] * (ll) y[i]) % MOD;
  }
  svert(x, true, MOD);
};
 
int glob = 0;
 
int orz[M];
int sans[M];
int sorz[M];
 
const int MOD2 = (int) (1e9) + 123123;
 
void dfs(int v, int pr = -1) {
  u[v] = 1;
  dp[v] = tin[v] = tt++;
  for (auto c : g[v]) {
    int to = c.to;
    if (to == pr) continue;
    if (u[to] == 0) {
      w[to] = c;
      par[to] = v;
      dfs(to, v);
      if (dp[to] > tin[v]) {
        glob ^= c.w;
      }
      dp[v] = min(dp[v], dp[to]);
    } else if (u[to] == 1) {
      dp[v] = min(dp[v], tin[to]);
      int x = v;
      vector <edge> e = {c};
      while (x != to) {
        e.push_back(w[x]);
        x = par[x];
      }
      for (int i= 0; i < M; i++) orz[i] = sorz[i] = 0;
      int xr = 0;
      for (auto c : e) {
        xr ^= c.w;
      }
      for (auto c : e) {
        orz[xr ^ c.w]++;
        sorz[xr ^ c.w]++;
      }
      mul(ans, orz, MOD);
      mul(sans, sorz, MOD2);
    }
  }
  u[v] = 2;
}
 
int main() {
  int n, m;
  scanf("%d%d",&n,&m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d",&u,&v,&w);
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  ans[0] = 1;
  sans[0] = 1;
  dfs(0);
  vector <int> ret(M), sret(M);
  for (int i = 0; i < M; i++) {
    ret[i ^ glob] += ans[i];
    sret[i ^ glob] += sans[i];
  }
  for (int i = 0; i < M; i++) {
    if (ret[i] || sret[i]) {
      cout << i << ' ' << ret[i] << '\n';
      return 0;
    }
  }
}
//300iq NB!