/**
 *    author:  tourist
 *    created: 03.01.2022 18:55:41       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  vector<long long> dist(n);
  vector<int> pv(n, -1);
  vector<int> order;
  function<void(int)> Dfs = [&](int v) {
    order.push_back(v);
    for (auto& p : g[v]) {
      int u = p.first;
      if (u != pv[v]) {
        pv[u] = v;
        dist[u] = dist[v] + p.second;
        Dfs(u);
      } 
    }
  };
  pv[0] = -1;
  dist[0] = 0;
  Dfs(0);
  assert((int) order.size() == n);
  int k;
  cin >> k;
  string zone_foo;
  cin >> zone_foo;
  vector<int> zone(n);
  for (int i = 0; i < n; i++) {
    zone[i] = (int) (zone_foo[i] - 'A');
    assert(0 <= zone[i] && zone[i] < k);
  }
  vector<long long> pass(k);
  for (int i = 0; i < k; i++) {
    cin >> pass[i];
  }
  vector<long long> fine(k);
  for (int i = 0; i < k; i++) {
    cin >> fine[i];
  }
  long long T;
  cin >> T;
  vector<int> up(n, -1);
  vector<int> mask(n, 0);
  vector<vector<long long>> coeff_max(n, vector<long long>(k, 0));
  for (int i : order) {
    if (pv[i] != -1) {
      if (zone[i] != zone[pv[i]]) {
        up[i] = pv[i];
      } else {
        up[i] = up[pv[i]];
      }
    } else {
      up[i] = -1;
    }
    int at = up[i];
    while (at != -1) {
      int nxt = up[at];
      long long L = dist[i] - dist[at];
      long long R = (nxt == -1 ? dist[i] : dist[i] - dist[nxt]);
      long long cf = (R + T - 1) / T - (L + T - 1) / T;
      long long cf_max = (R - L + T - 1) / T;
      coeff_max[i][zone[at]] += cf_max;
      assert(cf == cf_max || cf == cf_max - 1);
      if (cf < cf_max) {
        mask[i] |= (1 << zone[at]);
      }
      at = nxt;
    }
  }
  vector<vector<int>> un(n);
  for (int it = n - 1; it >= 0; it--) {
    int i = order[it];
    un[i].push_back(mask[i]);
    sort(un[i].begin(), un[i].end());
    un[i].resize(unique(un[i].begin(), un[i].end()) - un[i].begin());
    if (pv[i] != -1 && zone[i] == zone[pv[i]]) {
      un[pv[i]].insert(un[pv[i]].end(), un[i].begin(), un[i].end());
    }
  }
  vector<long long> limit(k);
  for (int i = 0; i < k; i++) {
    limit[i] = pass[i] / fine[i];
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1 || op == 2) {
      string foo;
      cin >> foo;
      int id = (int) (foo[0] - 'A');
      cin >> (op == 1 ? pass[id] : fine[id]);
      limit[id] = pass[id] / fine[id];
    }
    if (op == 3) {
      int u;
      cin >> u;
      --u;
      long long ans = (long long) 9e18;
      for (int ms : un[u]) {
        long long cur = 0;
        for (int j = 0; j < k; j++) {
          long long cf = coeff_max[u][j];
          if (ms & (1 << j)) {
            cf -= 1;
          }
          assert(cf >= 0);
          if (cf <= limit[j]) {
            cur += cf * fine[j];
          } else {
            cur += pass[j];
          }
        }
        ans = min(ans, cur);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}