/**
 *    author:  tourist
 *    created: 03.01.2022 18:00:52       
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
    long long a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    long long ans = 0;
    for (int rot = 0; rot < 2; rot++) {
      int k1 = 0;
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && s[i + 1] == '1') {
          k1 += 1;
        }
      }
      int k0 = 0;
      int r0 = 0;
      int e0 = 0;
      multiset<int> s0;
      int beg = 0;
      while (beg < n) {
        if (s[beg] == '1') {
          ++beg;
          continue;
        }
        int end = beg;
        while (end + 1 < n && s[end + 1] == '0') {
          end += 1;
        }
        if (beg == 0 || end == n - 1) {
          k0 += end - beg;
          e0 += 1;
        } else {
          if (end - beg > 0) {
            s0.insert(end - beg);
          } else {
            r0 += 1;
          }
        }
        beg = end + 1;
      }
      long long cur = 0;
      if (rot == 1) {
        if (k1 == 0) {
          continue;
        }
        k1 -= 1;
        cur += b;
        ans = max(ans, cur);
      }
      while (true) {
        if (k1 > 0) {
          if (!s0.empty()) {
            auto it = s0.begin();
            int num = *it;
            s0.erase(it);
            if (num - 1 > 0) {
              s0.insert(num - 1);
            } else {
              r0 += 1;
            }
            cur += a;
          } else {
            if (k0 > 0) {
              cur += a;
              k0 -= 1;
            } else {
              if (r0 > 0) {
                cur -= c;
                r0 -= 1;
                k1 += 1;
              } else {
                if (e0 > 0) {
                  cur -= c;
                  e0 -= 1;
                } else {
                  break;
                }
              }
            }
          }
        } else {
          if (!s0.empty() || k0 > 0) {
            ans = max(ans, cur + a);
          }
          if (r0 > 0) {
            cur -= c;
            r0 -= 1;
            k1 += 1;
          } else {
            break;
          }
        }
        ans = max(ans, cur);
        if (k1 == 0) {
          break;
        }
        k1 -= 1;
        cur += b;
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}