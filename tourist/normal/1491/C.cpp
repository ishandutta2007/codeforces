/**
 *    author:  tourist
 *    created: 28.02.2021 16:39:28       
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
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    dsu d(n + 1);
    for (int i = 0; i < n; i++) {
      if (s[i] == 1) {
        d.unite(i, i + 1);
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (i + s[i] > n) {
        ans += (i + s[i]) - n;
        s[i] = n - i;
        if (s[i] == 1) {
          d.unite(i, i + 1);
        }
      }
      while (s[i] > 1) {
        int j = i;
        while (j < n) {
          j = d.get(j);
          if (j == n) {
            break;
          }
          int val = s[j];
          if (s[j] == 2) {
            d.unite(j, j + 1);
          }
          s[j] = max(s[j] - 1, 1);
          j += val;
        }
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}