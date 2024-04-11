/**
 *    author:  wxhtzdy
 *    created: 21.09.2022 14:57:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int l;
  cin >> l;
  string s;
  cin >> s;
  int n = (int) s.size();
  auto Gen = [&](int m) {
    string s = string(l, '0');
    s[0] = '1';                     
    string res = "";
    while (res.size() < m) {
      res += s;
    }
    return res;
  };
  if (n % l != 0) {
    while (n % l != 0) {
      n += 1;
    }     
    cout << Gen(n) << '\n';
  } else {
    string ans;
    for (int i = 0; i < n; i++) {
      ans += s[i % l];
    }
    if (ans > s) {
      cout << ans << '\n';
    } else if (s == string(n, '9')) {         
      cout << Gen(n + l) << '\n';  
    } else {   
      int idx;
      for (int i = l - 1; i >= 0; i--) {
        if (s[i] != '9') {
          idx = i;
          break;
        }
      }
      s[idx] += 1;
      for (int i = idx + 1; i < l; i++) {
        s[i] = '0';
      }
      ans = "";
      for (int i = 0; i < n; i++) {
        ans += s[i % l];
      }
      cout << ans << '\n';
    }
  }                                                                   
  return 0;
}