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
 
const int N = 4010;
vector<int> g[N], order;
bool used[N];
int color[N];

void dfs(int v) {
  used[v] = true;
  //cout << v << endl;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  order.pb(v);
}

void dfs2(int v, int clr) {
  color[v] = clr;
  for (auto u : g[v]) {
    if (!color[u]) {
      dfs2(u, clr);
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
    //cout << T << endl;
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    int sz = 4 * n;
    for (int i = 1; i <= sz; i++) {
      used[i] = false;
      color[i] = 0;
      g[i] = {};
    }
    order = {};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        char x;
        cin >> x;
        if (x != a[i][j]) {
          g[i].pb(3 * n + j);
          g[n + j].pb(2 * n + i);
          g[2 * n + i].pb(n + j);
          g[3 * n + j].pb(i);
        }
        else {
          g[i].pb(n + j);
          g[n + j].pb(i);
          g[2 * n + i].pb(3 * n + j);
          g[3 * n + j].pb(2 * n + i);
        }
      }
    }
    for (int i = 1; i <= sz; i++) {
      if (!used[i]) {
        dfs(i);
      }
    }
    //cout << "OK" << endl;
    reverse(all(order));
    int cnt = 0;
    for (int v : order) {
      if (!color[v]) {
        dfs2(v, ++cnt);
      }
    }
    //cout << "OK2" << endl;
    bool ok = true;
    for (int i = 1; i <= 2 * n; i++) {
      if (color[i] == color[2 * n + i]) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  } 
}