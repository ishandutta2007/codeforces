/**
 *    author:  tourist
 *    created: 25.05.2022 21:54:45       
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
    string s;
    cin >> s;
    n *= 2;
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
      b[i + 1] = b[i] + (s[i] == '(' ? 1 : -1);
    }
    if (*min_element(b.begin(), b.end()) == 0) {
      cout << 0 << '\n';
      continue;
    }
    int L = 0, R = n;
    while (b[L + 1] >= 0) {
      L += 1;
    }
    while (b[R - 1] >= 0) {
      R -= 1;
    }
    L = (int) (max_element(b.begin(), b.begin() + L + 1) - b.begin());
    R = (int) (max_element(b.begin() + R, b.end()) - b.begin());
    {
      auto w = s;
      reverse(w.begin() + L, w.begin() + R);
      bool ok = true;
      int bal = 0;
      for (char c : w) {
        bal += (c == '(' ? 1 : -1);
        ok &= (bal >= 0);
      }
      if (ok) {
        cout << 1 << '\n';
        cout << L + 1 << " " << R << '\n';
        continue;
      }
    }
    int x = (int) (max_element(b.begin(), b.end()) - b.begin());
    cout << 2 << '\n';
    cout << 1 << " " << x << '\n';
    cout << x + 1 << " " << n << '\n';
  }
  return 0;
}