/**
 *    author:  tourist
 *    created: 25.05.2022 22:08:59       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    while (true) {
      dsu d(n);
      for (int i = 0; i < n; i++) {
        d.unite(i, a[i]);
      }
      bool found = false;
      for (int i = 0; i < n - 1; i++) {
        if (d.get(i) != d.get(i + 1)) {
          for (int j = 0; j < n; j++) {
            if (a[j] == i || a[j] == i + 1) {
              a[j] ^= i ^ (i + 1);
            }
          }
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    vector<int> b;
    int x = 0;
    for (int i = 0; i < n; i++) {
      b.push_back(x);
      x = a[x];
    }
    reverse(b.begin() + 1, b.end());
    for (int i = 0; i < n; i++) {
      cout << b[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}