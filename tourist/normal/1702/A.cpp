/**
 *    author:  tourist
 *    created: 10.07.2022 18:34:35       
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
    string s = to_string(n);
    string t = "1" + string(s.size() - 1, '0');
    int m = atoi(t.c_str());
    cout << n - m << '\n';
  }
  return 0;
}