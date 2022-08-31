/**
 *    author:  tourist
 *    created: 22.04.2022 18:36:41       
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
    for (int i = 0; i < n; i++) {
      a[i] -= i;
    }
    int L = *min_element(a.begin(), a.end());
    int R = *max_element(a.begin(), a.end());
    cout << (R - L <= 2 ? "YES" : "NO") << '\n';
  }
  return 0;
}