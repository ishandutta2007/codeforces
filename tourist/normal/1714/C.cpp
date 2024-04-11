/**
 *    author:  tourist
 *    created: 01.08.2022 17:36:52       
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
    int s;
    cin >> s;
    string res = "";
    for (int i = 9; i >= 1; i--) {
      if (s >= i) {
        res += (char) ('0' + i);
        s -= i;
      }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
  return 0;
}