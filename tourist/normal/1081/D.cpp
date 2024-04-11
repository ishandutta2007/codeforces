/**
 *    author:  tourist
 *    created: 16.12.2018 17:41:27       
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> mark(n, 0);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    x--;
    mark[x] = 1;
  }
  vector<tuple<int,int,int>> e(m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    e[i] = make_tuple(z, x, y);
  }
  sort(e.begin(), e.end());
  dsu d(n);
  int ans = -1;
  for (auto &t : e) {
    int x = get<1>(t);
    int y = get<2>(t);
    int cost = get<0>(t);
    int xx = d.get(x);
    int yy = d.get(y);
    if (xx != yy) {
      d.unite(xx, yy);
      mark[yy] += mark[xx];
      if (mark[yy] == k) {
        ans = cost;
        break;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans;
  }
  cout << '\n';
  return 0;
}