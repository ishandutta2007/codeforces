/**
 *    author:  tourist
 *    created: 22.01.2022 17:44:36       
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == string(s[i].rbegin(), s[i].rend())) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
      continue;
    }
    set<string> p;
    for (int i = 0; i < n; i++) {
      string x(s[i].rbegin(), s[i].rend());
      string y(s[i].rbegin(), prev(s[i].rend()));
      if (p.find(x) != p.end() || p.find(y) != p.end()) {
        ok = true;
        break;
      }
      p.insert(s[i]);
    }
    if (!ok) {
      p.clear();
      for (int i = n - 1; i >= 0; i--) {
        string x(next(s[i].rbegin()), s[i].rend());
        if (p.find(x) != p.end()) {
          ok = true;
          break;
        }
        p.insert(s[i]);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}