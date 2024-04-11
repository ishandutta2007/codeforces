/**
 *    author:  tourist
 *    created: 23.04.2022 18:06:43       
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
    string s;
    cin >> s;
    int b = 0;
    bool ok = true;
    for (char c : s) {
      b += (c == 'A' ? 1 : -1);
      ok &= (b >= 0);
    }
    ok &= (s.back() == 'B');
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}