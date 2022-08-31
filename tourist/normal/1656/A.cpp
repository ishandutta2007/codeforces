/**
 *    author:  tourist
 *    created: 24.03.2022 17:32:07       
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
    cout << (max_element(a.begin(), a.end()) - a.begin()) + 1 << " " << (min_element(a.begin(), a.end()) - a.begin()) + 1 << '\n';
  }
  return 0;
}