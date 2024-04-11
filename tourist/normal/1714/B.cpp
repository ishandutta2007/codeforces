/**
 *    author:  tourist
 *    created: 01.08.2022 17:36:11       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<int> s;
    for (int i = n - 1; i >= 0; i--) {
      if (s.find(a[i]) != s.end()) {
        break;
      }
      s.insert(a[i]);
    }
    cout << n - (int) s.size() << '\n';
  }
  return 0;
}