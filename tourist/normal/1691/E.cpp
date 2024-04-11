/**
 *    author:  tourist
 *    created: 31.05.2022 18:39:08       
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
    int n;
    cin >> n;
    vector<int> c(n), l(n), r(n);
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; i++) {
      cin >> c[i] >> l[i] >> r[i];
      ev.emplace_back(l[i], ~i);
      ev.emplace_back(r[i], i);
    }
    sort(ev.begin(), ev.end());
    vector<set<pair<int, int>>> s(2);
    dsu d(n);
    int ans = n;
    for (auto& e : ev) {
      int id = e.second;
      if (id < 0) {
        id = ~id;
        s[c[id]].emplace(r[id], id);
        int q = c[id] ^ 1;
        if (!s[q].empty()) {
          while (s[q].size() >= 2) {
            ans -= d.unite(id, s[q].begin()->second);
            s[q].erase(s[q].begin());
          }
          ans -= d.unite(id, s[q].begin()->second);
        }
      } else {
        s[c[id]].erase(make_pair(r[id], id));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}