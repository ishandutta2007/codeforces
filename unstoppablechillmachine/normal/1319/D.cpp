#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int INF = 1e9 + 10;
const int N = 2e5 + 10;
vector<int> g[N], g2[N];
int p[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[v].pb(u);
      g2[u].pb(v);
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> p[i];
    }
    int t = p[k];
    queue<int> q;
    q.push(t);
    vector<int> dist(n + 1, INF);
    dist[t] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : g[v]) {
        if (dist[u] == INF) {
          dist[u] = dist[v] + 1;
          q.push(u);
        }
      }
    }
    int mn = 0, mx = 0;
    for (int i = 1; i < k; i++) {
      if (dist[p[i + 1]] != dist[p[i]] - 1) {
        mn++;
        mx++;
      }
      else {
        bool ok = false;
        for (auto u : g2[p[i]]) {
          if (u != p[i + 1] && dist[p[i]] - 1 == dist[u]) {
            ok = true;
            break;
          }
        }
        if (ok) {
          mx++;
        }
      }
    }
    cout << mn << ' ' << mx << '\n';
}