/**
 *    author:  tourist
 *    created: 15.07.2022 17:37:49       
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
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<long long> l(c), r(c);
    vector<long long> len(c + 1);
    len[0] = n;
    for (int i = 0; i < c; i++) {
      cin >> l[i] >> r[i];
      len[i + 1] = len[i] + (r[i] - l[i] + 1);
    }
    while (q--) {
      long long k;
      cin >> k;
      assert(k <= len[c]);
      for (int i = c - 1; i >= 0; i--) {
        if (k > len[i]) {
          k = l[i] + (k - len[i] - 1);
        }
      }
      assert(k <= n);
      cout << s[k - 1] << '\n';
    }
  }
  return 0;
}