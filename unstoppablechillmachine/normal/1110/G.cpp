#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

void source() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(2 * n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[v].pb(u);
      g[u].pb(v);
    }
    vector<bool> w(n + 1);
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == 'W') {
        w[i] = true;
      }
    }
    int cnt3 = 0, cnt4 = 0;
    bool lol = false;
    /*vector<int> ccw(n + 1);
    for (int i = 1; i <= n; i++) {
      if (!w[i]) {
        for (auto u : g[i]) {
          ccw[i] += w[u];
        }
        if (ccw[i] >= 2) {
          lol = true;
        }
      } 
    }
    for (int i = 1; i <= n; i++) {
      if (!w[i]) {
        for (auto u : g[i]) {
          if (w[u] && ccw[u]) {
            lol = true;
          }
        }
      }
    }
    if (lol) {
      cout << "White\n";
      continue;
    }*/
    vector<int> wh;
    for (int i = 1; i <= n; i++) {
      if (w[i]) {
        wh.pb(n + i);
        g[n + i].pb(i);
        g[i].pb(n + i);
        cnt3++;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (SZ(g[i]) >= 3) {
        wh.pb(i);
      }
      if (SZ(g[i]) >= 4) {
        cnt4++;
      }
      else if (SZ(g[i]) >= 3) {
        cnt3++;
        int cc = 0;
        for (auto u : g[i]) {
          if (SZ(g[u]) > 1 || u > n) {
            cc++;
          }
        }
        if (cc > 1) {
          lol = true;
        }
      }
    }
    if (cnt4 > 0 || cnt3 > 2 || lol) {
      cout << "White\n";
      continue;
    }
    if (cnt3 < 2) {
      cout << "Draw\n"; 
      continue;
    }
    vector<int> dist(2 * n + 1, INF);
    dist[wh[0]] = 0;
    queue<int> q;
    q.push(wh[0]);
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
    cout << (dist[wh.back()] & 1 ? "Draw" : "White") << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}