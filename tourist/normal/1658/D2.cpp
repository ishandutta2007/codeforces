/**
 *    author:  tourist
 *    created: 27.03.2022 17:43:06       
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
    int l, r;
    cin >> l >> r;
    vector<int> a;
    vector<int> cc(30);
    for (int i = 0; i < r - l + 1; i++) {
      int x;
      cin >> x;
      a.push_back(x);
      for (int j = 0; j < 30; j++) {
        cc[j] += (x >> j) & 1;
      }
    }
    int n = r - l + 1;
    vector<int> dd(30);
    for (int i = l; i <= r; i++) {
      for (int j = 0; j < 30; j++) {
        dd[j] += (i >> j) & 1;
      }
    }
    int ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
      if (cc[bit] == 0 || cc[bit] == n) {
        if (cc[bit] != dd[bit]) {
          ans += (1 << bit);
        }
      } else {
        bool found = false;
        for (int me = 0; me < 2; me++) {
          for (int who = 0; who < 2; who++) {
            if (found) {
              continue;
            }
            int x = ans + (me << bit);
            vector<int> cnt(30);
            for (int i : a) {
              if (((i >> bit) & 1) == who) {
                for (int j = 0; j < 30; j++) {
                  cnt[j] += ((i >> j) & 1) ? 1 : -1;
                }
              } else {
                for (int j = 0; j < 30; j++) {
                  cnt[j] -= ((i >> j) & 1) ? 1 : -1;
                }
              }
            }
            for (int j = 0; j < bit; j++) {
              if (cnt[j] > 0) {
                x += (1 << j);
              }
            }
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
              b[i] = (a[i] ^ x);
            }
            sort(b.begin(), b.end());
            bool ok = true;
            for (int i = 0; i < n; i++) {
              ok &= (b[i] == l + i);
            }
            if (ok) {
              found = true;
              ans = x;
            }
          }
        }
        assert(found);
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}