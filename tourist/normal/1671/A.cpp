/**
 *    author:  tourist
 *    created: 22.04.2022 18:35:32       
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
    bool ok = true;
    for (int i = 0; i < (int) s.size(); i++) {
      bool good = false;
      if (i > 0 && s[i] == s[i - 1]) good = true;
      if (i < (int) s.size() - 1 && s[i] == s[i + 1]) good = true;
      ok &= good;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}