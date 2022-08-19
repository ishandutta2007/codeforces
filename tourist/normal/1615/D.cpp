/**
 *    author:  tourist
 *    created: 24.12.2021 17:59:32       
**/
#include <bits/stdc++.h>

using namespace std;

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
    dsu d(2 * n);
    vector<int> x(n - 1), y(n - 1), v(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> x[i] >> y[i] >> v[i];
      --x[i]; --y[i];
      if (v[i] >= 0) {
        int t = __builtin_popcount(v[i]) % 2;
        if (t == 0) {
          d.unite(x[i], y[i]);
          d.unite(x[i] + n, y[i] + n);
        } else {
          d.unite(x[i], y[i] + n);
          d.unite(x[i] + n, y[i]);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      --a; --b;
      if (p == 0) {
        d.unite(a, b);
        d.unite(a + n, b + n);
      } else {
        d.unite(a, b + n);
        d.unite(a + n, b);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (d.get(i) == d.get(i + n)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i < n; i++) {
      if (d.get(i) == d.get(0) || d.get(i + n) == d.get(0)) {
        continue;
      }
      d.unite(0, i);
      d.unite(0 + n, i + n);
    }
    for (int i = 0; i < n - 1; i++) {
      if (v[i] == -1) {
        if (d.get(x[i]) == d.get(y[i])) {
          v[i] = 0;
        } else {
          v[i] = 1;
        }
      }
      cout << x[i] + 1 << " " << y[i] + 1 << " " << v[i] << '\n';
    }
  }
  return 0;
}