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
 
const int INF = 1e9 + 10;
const int N = 2e5 + 10;
vector<pair<int, int>> g[4 * N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    for (int mask1 = 0; mask1 < 4; mask1++) {
      for (int mask2 = 0; mask2 < 4; mask2++) {
        if ((mask1 & mask2) != mask1) {
          continue;
        } 
        int coef = 1;
        if (mask2 % 2 > mask1 % 2) {
          coef++;
        }
        if ((mask2 / 2) % 2 > (mask1 / 2) % 2) {
          coef--;
        }
        g[4 * (u - 1) + mask1 + 1].pb({4 * (v - 1) + mask2 + 1, c * coef});
        g[4 * (v - 1) + mask1 + 1].pb({4 * (u - 1) + mask2 + 1, c * coef});
      }
    }
  }
  vector<int> dist(4 * n + 1, 1e18);
  dist[1] = 0;
  set<pair<int, int>> st;
  for (int i = 1; i <= 4 * n; i++) {
    st.insert({dist[i], i});
  }
  while (!st.empty()) {
    int v = st.begin()->S;
    st.erase(st.begin());
    for (auto u : g[v]) {
      if (dist[v] + u.S < dist[u.F]) {
        st.erase({dist[u.F], u.F});
        dist[u.F] = dist[v] + u.S;
        st.insert({dist[u.F], u.F});
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << dist[4 * i] << ' ';
  }
  cout << '\n';
}