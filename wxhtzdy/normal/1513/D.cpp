/**
 *    author:  milos
 *    created: 09.08.2021 21:07:56       
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
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    dsu d(n);
    int k = n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[id[i]] >= p) {
        continue;
      }
      int L = id[i] - 1, R = id[i] + 1;
      while (L >= 0 && a[L] % a[id[i]] == 0 && d.unite(id[i], L)) {
        ans += a[id[i]];
        k--;
        L--;
      }
      while (R < n && a[R] % a[id[i]] == 0 && d.unite(id[i], R)) {
        ans += a[id[i]];
        k--;
        R++;
      }
    }
    cout << ans + (k - 1) * 1LL * p << '\n';
  }  
  return 0;
}