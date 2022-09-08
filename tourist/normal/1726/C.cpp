/**
 *    author:  tourist
 *    created: 06.09.2022 17:41:02       
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
    n *= 2;
    string s;
    cin >> s;
    vector<vector<int>> at(2 * n + 3);
    int bal = n + 1;
    at[bal].push_back(0);
    int ans = n;
    dsu d(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        bal += 1;
      } else {
        bal -= 1;
        int limit = (at[bal - 1].empty() ? -1 : at[bal - 1].back());
        for (int j = (int) at[bal].size() - 1; j >= 0 && j >= (int) at[bal].size() - 2; j--) {
          if (at[bal][j] < limit) {
            break;
          }
          if (d.unite(at[bal][j], i)) {
            ans -= 1;
          }
        }
      }
      at[bal].push_back(i + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}