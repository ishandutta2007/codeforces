/**
 *  author: milos
 *  created: 05.01.2021 06:31:36
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
    int ans = 0;
    dsu d(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if (x == y) {
        continue;
      }
      if (!d.unite(x, y)) {
        ans += 1;
      }
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}