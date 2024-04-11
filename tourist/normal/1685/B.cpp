/**
 *    author:  tourist
 *    created: 25.05.2022 21:38:19       
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int n = (int) s.size();
    int as = a + c + d;
    int cnt = 0;
    for (char ch : s) {
      cnt += (ch == 'A');
    }
    if (as != cnt) {
      cout << "NO" << '\n';
      continue;
    }
    int any = 0;
    int total = 0;
    vector<int> cs;
    vector<int> ds;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && s[end + 1] != s[end]) {
        end += 1;
      }
      int cc = end - beg;
      if (cc > 0) {
        total += cc / 2;
        if (cc % 2 == 0) {
          any += cc / 2;
        } else {
          if (s[beg] == 'A') {
            cs.push_back(cc / 2);
          } else {
            ds.push_back(cc / 2);
          }
        }
      }
      beg = end + 1;
    }
    sort(cs.begin(), cs.end());
    sort(ds.begin(), ds.end());
    int rem_c = c;
    int rem_d = d;
    for (int x : cs) {
      if (rem_c >= x + 1) {
        rem_c -= x + 1;
        total += 1;
      }
    }
    for (int x : ds) {
      if (rem_d >= x + 1) {
        rem_d -= x + 1;
        total += 1;
      }
    }
    cout << (total >= c + d ? "YES" : "NO") << '\n';
  }
  return 0;
}