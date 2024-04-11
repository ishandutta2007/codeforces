/**
 *    author:  tourist
 *    created: 18.07.2022 18:53:23       
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> u(m), v(m);
    for (int i = 0; i < m; i++) {
      cin >> u[i] >> v[i];
      --u[i]; --v[i];
    }
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
      cin >> l[i] >> r[i];
      --l[i]; --r[i];
    }
    vector<int> low(q);
    vector<int> high(q, m);
    while (true) {
      vector<int> mid(q);
      bool any = false;
      vector<vector<int>> at(m);
      for (int i = 0; i < q; i++) {
        if (low[i] < high[i]) {
          mid[i] = (low[i] + high[i]) >> 1;
          any = true;
          at[mid[i]].push_back(i);
        }
      }
      if (!any) {
        break;
      }
      vector<int> p(n);
      iota(p.begin(), p.end(), 0);
      vector<vector<int>> a(n);
      for (int i = 0; i < n; i++) {
        a[i].push_back(i);
      }
      dsu d(n);
      for (int i = 0; i < m; i++) {
        for (int j : at[i]) {
          if (d.get(l[j]) >= r[j]) {
            high[j] = mid[j];
          } else {
            low[j] = mid[j] + 1;
          }
        }
        int x = p[u[i]];
        int y = p[v[i]];
        if (x == y) {
          continue;
        }
        if (a[x].size() > a[y].size()) {
          swap(x, y);
        }
        for (int j : a[x]) {
          if (j > 0 && p[j - 1] == y) {
            d.unite(j - 1, j);
          }
          if (j < n - 1 && p[j + 1] == y) {
            d.unite(j, j + 1);
          }
        }
        for (int j : a[x]) {
          p[j] = y;
          a[y].push_back(j);
        }
        vector<int>().swap(a[x]);
      }
    }
    for (int i = 0; i < q; i++) {
      cout << low[i] << " \n"[i == q - 1];
    }
  }
  return 0;
}