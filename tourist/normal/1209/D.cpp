/**
 *    author:  tourist
 *    created: 14.09.2019 16:16:25       
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
  int n, k;
  cin >> n >> k;
  dsu d(n);
  int edges = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (d.unite(x, y)) {
      edges++;
    }
  }
  vector<int> cc(n, 0);
  for (int i = 0; i < n; i++) {
    ++cc[d.get(i)];
  }
  int comps = 0;
  int nver = 0;
  for (int i = 0; i < n; i++) {
    if (cc[i] > 1) {
      ++comps;
      nver += cc[i];
    }
  }
  int happy = nver - comps;
  cout << k - happy << '\n';
  return 0;
}