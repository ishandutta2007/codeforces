#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
vector<int> g[N];
int h[N], p[N];

void dfs(int v, int par, int curh) {
  h[v] = curh;
  p[v] = par;
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v, curh + 1);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[v].pb(u);
    g[u].pb(v);
  }
  int root = 0;
  for (int i = 1; i <= n; i++) {
    if (SZ(g[i]) > 1) {
      root = i;
    }
  }		
  dfs(root, 0, 0);
  int mn = 1;
  int fir = 0;
  for (int i = 1; i <= n; i++) {
    if (SZ(g[i]) == 1) {
      fir = i;
      break;
    }
  }
  for (int i = fir + 1; i <= n; i++) {
    if (SZ(g[i]) == 1) {
      if (h[i] % 2 != h[fir] % 2) {
        mn = 3;
        break;
      }
    }
  }
  int ans = n - 1;
  for (int i = 1; i <= n; i++) {
    vector<int> kek;
    for (auto u : g[i]) {
      if (SZ(g[u]) == 1) {
        kek.pb(u);
      }
    }
    if (SZ(kek) > 1) {
      ans -= SZ(kek) - 1;
    }
  }
  cout << mn << ' ' << ans << '\n';
}