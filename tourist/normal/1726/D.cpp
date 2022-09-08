/**
 *    author:  tourist
 *    created: 06.09.2022 17:59:02       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    vector<vector<pair<int, int>>> g(n);
    vector<int> bad;
    string res(m, '0');
    dsu d(n);
    for (int i = 0; i < m; i++) {
      cin >> u[i] >> v[i];
      --u[i]; --v[i];
      if (d.unite(u[i], v[i])) {
        res[i] = '1';
        g[u[i]].emplace_back(v[i], i);
        g[v[i]].emplace_back(u[i], i);
      } else {
        bad.push_back(i);
      }
    }
    if (bad.size() == 3) {
      vector<pair<int, int>> all;
      for (int i : bad) {
        all.emplace_back(min(u[i], v[i]), max(u[i], v[i]));
      }
      sort(all.begin(), all.end());
      int x = all[0].first;
      int y = all[0].second;
      int z = all[1].second;
      if (all == vector<pair<int, int>>{{x, y}, {x, z}, {y, z}}) {
        vector<int> pr(n, -1);
        vector<int> que(1, x);
        pr[x] = -2;
        for (int b = 0; b < (int) que.size(); b++) {
          for (auto& p : g[que[b]]) {
            int to = p.first;
            if (pr[to] == -1) {
              que.push_back(to);
              pr[to] = p.second;
            }
          }
        }
        for (int i : bad) {
          if (min(u[i], v[i]) == x && max(u[i], v[i]) == y) {
            swap(res[pr[y]], res[i]);
            break;
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}