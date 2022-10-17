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
 
const int N = 3e5 + 10;
int h[N];
bool used[N], can[N];
vector<int> g[N], take;

void dfs(int v, int ch = 0) {
  h[v] = ch;
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u, ch + 1);
    }
  }
}

void dfs2(int v) {
  if (can[v]) {
    take.pb(v);
    for (auto u : g[v]) {
      can[u] = false;
    }
  }
  for (auto u : g[v]) {
    if (h[u] == h[v] + 1) {
      dfs2(u);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      used[i] = false;
      can[i] = true;
      g[i] = {};
    }
    take = {};
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1);
    bool ok = true;    
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    dfs2(1);
    cout << "YES\n";
    cout << SZ(take) << '\n';
    sort(all(take));
    for (auto x : take) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}