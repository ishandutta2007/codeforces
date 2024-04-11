/**
 *    author:  tourist
 *    created: 24.07.2020 17:34:32       
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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    dsu d(26);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ans = -1;
        break;
      }
      if (d.unite((int) (a[i] - 'a'), (int) (b[i] - 'a'))) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}