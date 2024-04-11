#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 2e5 + 10;
int used[N];
bool was[N];
vector<int> g[N], rg[N], order;

void dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
    else if (used[u] == 1) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  used[v] = 2;
  order.pb(v);
}

void go1(int v) {
  was[v] = true;
  for (int u : g[v]) {
    if (!was[u]) {
      go1(u);
    }
  }
}

void go2(int v) {
  was[v] = true;
  for (int u : rg[v]) {
    if (!was[u]) {
      go2(u);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> in(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    rg[v].pb(u);
  } 
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  } 
  vector<int> mn(n + 1, 1e9), mn2(n + 1, 1e9);
  for (auto v : order) {
    for (auto u : g[v]) {
      mn[v] = min(mn[v], min(mn[u], u));
    }
  }
  reverse(all(order));
  for (auto v : order) {
    for (auto u : rg[v]) {
      mn2[v] = min(mn2[v], min(mn2[u], u));
    }
  }
  int cnt = 0;
  vector<char> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!was[i] && i < mn[i] && i < mn2[i]) {
      cnt++;
      //go1(i);
      //go2(i);
      ans[i] = 'A';
    }
    else {
      ans[i] = 'E';
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
}