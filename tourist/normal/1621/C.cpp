/**
 *    author:  tourist
 *    created: 03.01.2022 17:39:38       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto Ask = [&](int x) {
      cout << "? " << x + 1 << endl;
      int y;
      cin >> y;
      return y;
    };
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) {
        continue;
      }
      int x = Ask(i);
      vector<int> c(1, x);
      while (true) {
        c.push_back(Ask(i));
        if (c.back() == c[0]) {
          c.pop_back();
          break;
        }
      }
      int sz = (int) c.size();
      for (int j = 0; j < sz; j++) {
        p[c[j] - 1] = c[(j + 1) % sz] - 1;
      }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
      cout << " " << p[i] + 1;
    }
    cout << endl;
  }
  return 0;
}