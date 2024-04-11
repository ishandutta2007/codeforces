/**
 *    author:  tourist
 *    created: 10.07.2022 18:43:02       
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<vector<int>> trie(1, vector<int>(2, -1));
    vector<int> val(1, 0);
    bool ok = true;
    for (int i = 0; i < 2 * n; i++) {
      int x = (i < n ? b[i] : a[i - n]);
      int sign = (i < n ? 1 : -1);
      while (x % 2 == 0) {
        x /= 2;
      }
      int bit = 30;
      while (!(x & (1 << bit))) {
        bit -= 1;
      }
      int t = 0;
      for (int j = bit; j >= 0; j--) {
        int d = (x >> j) & 1;
        if (trie[t][d] == -1) {
          trie[t][d] = (int) trie.size();
          trie.emplace_back(2, -1);
          val.push_back(0);
        }
        t = trie[t][d];
        val[t] += sign;
        if (val[t] < 0) {
          ok = false;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}