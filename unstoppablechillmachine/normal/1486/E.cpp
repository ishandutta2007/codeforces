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

const int INF = 1e9 + 10;
const int N = 1e5 + 10;
const int W = 51;
int dist[N][W];
vector<pair<int, int>> g[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].pb({v, c});
    g[v].pb({u, c});
  }
  set<pair<int, pair<int, int>>> st;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < W; j++) {
      dist[i][j] = INF;
    }
  }
  dist[1][0] = 0;
  st.insert(make_pair(0, make_pair(1, 0)));
  while (!st.empty()) {
    int v = st.begin()->S.F, k = st.begin()->S.S;
    st.erase(st.begin());
    if (!k) {
      for (auto u : g[v]) {
        int vl = dist[v][k] + u.S * u.S;
        if (vl < dist[u.F][u.S]) {
          if (dist[u.F][u.S] < INF) {
            st.erase(make_pair(dist[u.F][u.S], make_pair(u.F, u.S)));
          }
          dist[u.F][u.S] = vl;
          st.insert(make_pair(dist[u.F][u.S], make_pair(u.F, u.S)));
        }
      }
    }
    else {
      for (auto u : g[v]) {
        int vl = dist[v][k] + 2 * k * u.S + u.S * u.S; 
        if (vl < dist[u.F][0]) {
          if (dist[u.F][0] < INF) {
            st.erase(make_pair(dist[u.F][0], make_pair(u.F, 0)));
          }
          dist[u.F][0] = vl;
          st.insert(make_pair(dist[u.F][0], make_pair(u.F, 0)));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i][0] < INF) {
      cout << dist[i][0] << ' ';
    }
    else {
      cout << -1 << ' ';
    }
  }
  cout << '\n';
}