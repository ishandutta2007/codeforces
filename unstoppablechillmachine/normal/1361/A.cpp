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

const int N = 5e5 + 10;
vector<int> g[N], kek[N], order;
bool used[N], alr[N];
int a[N], was[N], timer;
void dfs(int v) {
  used[v] = true;
  for (auto u : kek[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  order.pb(v);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (auto j : g[i]) {
      if (a[i] == a[j]) {
        cout << -1 << '\n';
        exit(0);
      }
      if (a[i] < a[j]) {
        kek[i].pb(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(all(order));
  for (auto it : order) {
    timer++;
    alr[it] = true;
    for (auto fuck : g[it]) {
      if (alr[fuck]) {
        was[a[fuck]] = timer;
      }
    }
    int cur = 1;
    while (was[cur] == timer) {
      cur++;
    }
    if (a[it] != cur) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  for (auto it : order) {
    cout << it << ' ';
  }
  cout << '\n';
}