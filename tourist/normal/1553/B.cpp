/**
 *    author:  tourist
 *    created: 22.07.2021 17:38:06       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        bool ok = true;
        int ptr = 0;
        for (int k = i; k <= j; k++) {
          if (ptr == m || s[k] != t[ptr]) {
            ok = false;
            break;
          }
          ++ptr;
        }
        for (int k = j - 1; k >= 0; k--) {
          if (ptr == m) {
            break;
          }
          if (s[k] != t[ptr]) {
            ok = false;
            break;
          }
          ++ptr;
        }
        if (ok && ptr == m) {
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}