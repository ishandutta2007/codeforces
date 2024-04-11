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

const int N = 110;
const int INF = 1e9 + 10;
vector<int> g[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(n + 1);
  vector<vector<int>> cnt(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }  
  for (int i = 1; i <= n; i++) {
    d[i].resize(n + 1, INF);
    cnt[i].resize(n + 1);
    d[i][i] = 0;
    cnt[i][i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : g[v]) {
        if (d[i][u] == INF) {
          d[i][u] = d[i][v] + 1;
          q.push(u);
          cnt[i][u] = cnt[i][v];
        }
        else if (d[i][v] + 1 == d[i][u]) {
          cnt[i][u] += cnt[i][v];
        }
      }
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int csum = 0;
    for (int v : g[i]) {
      if (d[1][i] + d[v][n] + 1 == d[1][n]) {
        csum += cnt[1][i] * cnt[v][n];
      }
      if  (d[1][v] + d[i][n] + 1 == d[1][n]) {
        csum += cnt[1][v] * cnt[i][n];
      }
    }
    mx = max(mx, csum);
  }
  cout << fixed << setprecision(10) << (ld)mx / (ld)cnt[1][n] << '\n';
}