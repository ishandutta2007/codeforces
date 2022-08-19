/**
 *    author:  tourist
 *    created: 28.11.2021 17:43:04       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;
  vector<int> sz;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      sz[x] = 0;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, dd;
  cin >> n >> dd;
  dsu d(n);
  int cc = 1;
  for (int it = 1; it <= dd; it++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (!d.unite(x, y)) {
      cc += 1;
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (d.get(i) == i) {
        b.push_back(d.sz[i]);
      }
    }
    sort(b.rbegin(), b.rend());
    assert(cc <= (int) b.size());
    cout << accumulate(b.begin(), b.begin() + cc, 0) - 1 << '\n';
  }
  return 0;
}