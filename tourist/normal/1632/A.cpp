/**
 *    author:  tourist
 *    created: 30.01.2022 20:17:55       
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
    cout << (n == 1 || (n == 2 && s[0] != s[1]) ? "YES" : "NO") << '\n';
  }
  return 0;
}