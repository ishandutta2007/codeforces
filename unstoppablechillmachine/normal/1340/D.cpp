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

#define time flexflex

const int N = 1e5 + 10;
vector<int> g[N];
int mx;

vector<pair<int, int>> path;

void go(int v, int time, int p = 0) {
  path.pb({v, time});
  int to_time = time - 1;
  int ost = SZ(g[v]);
  if (p != 0) {
    ost--;
  }
  for (auto u : g[v]) {
    if (u != p) {
      if (time == mx) {
        path.pb({v, to_time - ost});
        time = to_time - ost;
      }
      ost--;
      go(u, time + 1, v);
      path.pb({v, ++time});
    }
  }
  if (time != to_time && v != 1) {
    path.pb({v, to_time});
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
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    mx = max(mx, SZ(g[i]));
  }
  go(1, 0);
  cout << SZ(path) << '\n';
  for (auto it : path) {
    cout << it.F << ' ' << it.S << '\n';  
  }
}