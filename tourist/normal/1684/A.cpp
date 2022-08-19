/**
 *    author:  tourist
 *    created: 19.05.2022 18:35:05       
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
    if (s.size() == 2) {
      cout << s[1] << '\n';
    } else {
      cout << *min_element(s.begin(), s.end()) << '\n';
    }
  }
  return 0;
}