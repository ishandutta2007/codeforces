/**
 *    author:  tourist
 *    created: 30.09.2022 17:37:39       
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
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
      cin >> s[i];
    }
    if (k == 1) {
      cout << "YES" << '\n';
      continue;
    }
    vector<int> d(k - 1);
    for (int i = 0; i < k - 1; i++) {
      d[i] = s[i + 1] - s[i];
    }
    if (!is_sorted(d.begin(), d.end())) {
      cout << "NO" << '\n';
      continue;
    }
    if ((long long) (n - k + 1) * d[0] >= s[0]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}