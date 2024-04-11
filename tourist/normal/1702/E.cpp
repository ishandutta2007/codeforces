/**
 *    author:  tourist
 *    created: 10.07.2022 18:40:44       
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
    vector<int> deg(n);
    dsu d(2 * n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      deg[x] += 1;
      deg[y] += 1;
      d.unite(x, y + n);
      d.unite(x + n, y);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (deg[i] > 2) {
        ok = false;
      }
      if (d.get(i) == d.get(i + n)) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}