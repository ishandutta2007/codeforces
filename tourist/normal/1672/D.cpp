/**
 *    author:  tourist
 *    created: 23.04.2022 18:21:56       
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
      --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    bool ok = true;
    vector<int> extra(n);
    int i = n - 1;
    int j = n - 1;
    while (i >= 0) {
      if (j >= 0 && a[i] == b[j]) {
        int v = a[i];
        while (i >= 0 && a[i] == v) {
          i -= 1;
          extra[v] -= 1;
        }
        while (j >= 0 && b[j] == v) {
          j -= 1;
          extra[v] += 1;
        }
        if (extra[v] < 0) {
          ok = false;
          break;
        }
      } else {
        if (extra[a[i]] == 0) {
          ok = false;
          break;
        }
        extra[a[i]] -= 1;
        i -= 1;
      }
    }
    for (int i = 0; i < n; i++) {
      ok &= (extra[i] == 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}