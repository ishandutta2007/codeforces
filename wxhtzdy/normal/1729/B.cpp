/**
 *    author:  wxhtzdy
 *    created: 12.09.2022 16:38:52
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
    vector<char> ans;
    for (int i = 0; i < n; i++) {
      int ptr = i;
      while (ptr + 1 < n && s[ptr] != '0') {
        ptr += 1;
      }
      if (ptr + 1 < n && s[ptr + 1] == '0') {
        ptr += 1;
      }
      if (s[ptr] == '0') {
        for (int j = i; j < ptr - 2; j++) {
          ans.push_back((char) (s[j] - '1' + 'a'));  
        }
        ans.push_back((char) (((s[ptr - 2] - '0') * 10) + (s[ptr - 1] - '1') + 'a'));
      } else {
        for (int j = i; j <= ptr; j++) {
          ans.push_back((char) (s[j] - '1' + 'a'));
        }
      } 
      i = ptr;
    }
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}