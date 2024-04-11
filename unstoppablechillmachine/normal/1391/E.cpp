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
vector<int> g[N], have[N];
int pr[N], h[N];

void dfs(int v, int p = 0, int ch = 1) {
  pr[v] = p;
  h[v] = ch;
  have[ch].pb(v);
  //cout << v << ' ' << ch << '\n';
  for (auto u : g[v]) {
    if (!h[u]) {
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
  	int n, m;
  	cin >> n >> m;
    //cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
      g[i] = {};
      have[i] = {};
      h[i] = 0;
    }
  	for (int i = 0; i < m; i++) {
  		int u, v;
  		cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
  	}
    dfs(1);
    vector<int> path;
    for (int i = 1; i <= n; i++) {
      if (h[i] >= (n + 1) / 2) {
        int cur = i;
        while (cur) {
          path.pb(cur);
          cur = pr[cur];
        }
        break;
      }
    }
    if (!path.empty()) {
      assert(SZ(path) >= (n + 1) / 2);
      cout << "PATH\n" << SZ(path) << '\n';
      for (auto it : path) {
        cout << it << ' ';
      }
      cout << '\n';
    }
    else {
      vector<pair<int, int>> pars;
      for (int i = 1; i <= n; i++) {
        while (SZ(have[i]) > 1) {
          int v = have[i].back();
          have[i].pop_back();
          pars.pb({v, have[i].back()});
          have[i].pop_back();
        }
      }
      cout << "PAIRING\n";
      cout << SZ(pars) << '\n';
      for (auto it : pars) {
        cout << it.F << ' ' << it.S << '\n';
      }
    }
  }
}