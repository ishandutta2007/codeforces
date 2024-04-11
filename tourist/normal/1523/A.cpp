/**
 *    author:  tourist
 *    created: 30.05.2021 17:34:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int beg = 0;
    while (beg < n) {
      if (s[beg] == '1') {
        ++beg;
        continue;
      }
      int end = beg;
      while (end + 1 < n && s[end + 1] == '0') {
        ++end;
      }
      if (beg == 0 && end == n - 1) {
      } else {
        if (beg == 0) {
          for (int j = end; j >= beg && j >= end - m + 1; j--) {
            s[j] = '1';
          }
        } else {
          if (end == n - 1) {
            for (int j = beg; j <= end && j <= beg + m - 1; j++) {
              s[j] = '1';
            }
          } else {
            int i = beg;
            int j = end;
            for (int it = 0; i < j && it < m; it++) {
              s[i] = s[j] = '1';
              i += 1;
              j -= 1;
            }
          }
        }
      }
      beg = end + 1;
    }
    cout << s << '\n';
  }
  return 0;
}