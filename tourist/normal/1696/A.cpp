/**
 *    author:  tourist
 *    created: 25.06.2022 18:24:34       
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
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(mx, a[i] | z);
    }
    cout << mx << '\n';
  }
  return 0;
}