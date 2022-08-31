/**
 *    author:  tourist
 *    created: 14.02.2022 20:15:27       
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int j = 0;
    while (j < n && p[j] == j + 1) {
      ++j;
    }
    if (j < n) {
      reverse(p.begin() + j, min_element(p.begin() + j, p.end()) + 1);
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}