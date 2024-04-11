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
int h[N];
void dfs(int v, int p, int ch) {
  h[v] = ch;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, ch + 1);
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
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    if (db < 2 * da + 1) {
      cout << "Alice\n";
      continue;
    }
    dfs(a, 0, 0);
    if (h[b] <= da) {
      cout << "Alice\n";
      continue;
    }
    pair<int, int> mx = {0, 0};
    for (int i = 1; i <= n; i++) {
      mx = max(mx, make_pair(h[i], i));
    }
    dfs(mx.S, 0, 0);
    int diam = 0;
    for (int i = 1; i <= n; i++) {
      diam = max(diam, h[i]);
    }
    if (diam >= 2 * da + 1) {
      cout << "Bob\n";
    }
    else {
      cout << "Alice\n";
    }
  } 
}