/**
 *    author:  tourist
 *    created: 10.07.2022 18:36:23       
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
    int n = (int) s.size();
    int ans = 0;
    int beg = 0;
    while (beg < n) {
      ans += 1;
      int end = beg;
      set<char> c;
      c.insert(s[beg]);
      while (end + 1 < n) {
        if (c.size() == 3 && c.find(s[end + 1]) == c.end()) {
          break;
        }
        c.insert(s[end + 1]);
        end += 1;
      }
      beg = end + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}