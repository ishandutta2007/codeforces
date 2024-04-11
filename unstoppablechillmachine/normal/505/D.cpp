#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int N = 1e5 + 10;
vector<int> g[N], rg[N], gg[N], order;
int c[N], x[N];
bool used[N], kek;

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  order.pb(v);
}

void dfs2(int v, int color) {
  c[v] = color;
  x[color]++;
  for (auto u : rg[v]) {
    if (!c[u]) {
      dfs2(u, color);
    }
  }
}

void go(int v) {
  used[v] = true;
  if (x[v] > 1) {
    kek = true;
  }
  for (auto u : gg[v]) {
    if (!used[u]) {
      go(u);
    }
  }  
}

signed main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edge;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    rg[v].pb(u);
    edge.pb({u, v});
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(all(order));
  int cnt = 0;
  for (int v : order) {
    if (!c[v]) {
      dfs2(v, ++cnt);
    }
  }
  /*for (int i = 1; i <= n; i++) {
    cout << c[i] << '\n';
  }*/ 
  ll ans = 0;
  for (auto it : edge) {
    if (c[it.F] != c[it.S]) {
      gg[c[it.F]].pb(c[it.S]);
      gg[c[it.S]].pb(c[it.F]);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    sort(all(gg[i]));
    gg[i].resize(unique(all(gg[i])) - gg[i].begin());
    used[i] = false;
  }
  int comps = 0;
  for (int i = 1; i <= cnt; i++) {
    if (!used[i]) {
      kek = false;
      go(i);
      comps++;
      if (kek) {
        ans++;
      }
    }
  }
  ans += n - comps;
  cout << ans << '\n';
}