/**
 *    author:  wxhtzdy
 *    created: 25.01.2022 21:02:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto Test = [&](char c) {
      int ans = n;
      int beg = 0, end = n - 1;
      while (beg < end) {
        if (s[beg] != s[end]) {
          if (s[beg] == c) {
            beg += 1;
            ans -= 1;
          } else if (s[end] == c) {
            end -= 1;
            ans -= 1;
          } else {
            return (int) 1e9;
          }
        } else {
          beg += 1;
          end -= 1;
        }
      }
      return n - ans;
    };
    int ans = 1e9;
    for (char c = 'a'; c <= 'z'; c++) {
      ans = min(ans, Test(c));
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }                                                                    
  return 0;
}