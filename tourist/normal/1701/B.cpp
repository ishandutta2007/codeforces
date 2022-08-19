/**
 *    author:  tourist
 *    created: 08.07.2022 18:36:07       
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
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        int j = i;
        while (j <= n) {
          a.push_back(j);
          j *= 2;
        }
      }
    }
    cout << 2 << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}