/**
 *    author:  tourist
 *    created: 25.12.2020 15:19:56       
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      e[i] = make_tuple(z, x, y);
    }
    sort(e.begin(), e.end());
    dsu d(n);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      int x = get<1>(e[i]);
      int y = get<2>(e[i]);
      if (d.unite(x, y)) {
        ans += max(get<0>(e[i]) - k, 0);
      }
    }
    if (ans == 0) {
      ans = (int) 2e9;
      for (int i = 0; i < m; i++) {
        ans = min(ans, 0LL + abs(get<0>(e[i]) - k));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}