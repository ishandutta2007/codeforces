/**
 *    author:  tourist
 *    created: 30.01.2022 20:27:46       
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
    int p = 1;
    while (p * 2 < n) {
      p <<= 1; // p *= 2
    }
    for (int i = p - 1; i >= 0; i--) {
      cout << i << " ";
    }
    cout << p;
    for (int i = p + 1; i < n; i++) {
      cout << " " << i;
    }
    cout << '\n';
  }
  return 0;
}