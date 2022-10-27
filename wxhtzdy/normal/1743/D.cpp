/**
 *    author:  wxhtzdy
 *    created: 18.10.2022 18:17:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = s;           
  for (int iter = 0; iter < min(n, 50); iter++) {
    string nans = s;
    for (int i = 0; i < n - iter; i++) {
      if (s[i] == '1') {
        nans[i + iter] = '1';
      }
    }  
    ans = max(ans, nans);
  }
  reverse(ans.begin(), ans.end());
  while (ans.size() > 1 && ans.back() == '0') {
    ans.pop_back();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';                                                  
  return 0;
}