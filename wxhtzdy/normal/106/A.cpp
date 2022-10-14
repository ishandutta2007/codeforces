/**
 *    author:  wxhtzdy
 *    created: 23.08.2022 12:28:52
**/
#include <bits/stdc++.h>

using namespace std;

string str = "6789TJQKA";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  char t;
  cin >> t;
  string a, b;
  cin >> a >> b;
  if (a[1] == t && b[1] != t) {
    cout << "YES" << '\n';
    return 0;
  }
  auto Index = [&](char c) {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == c) {
        return i;
      }
    }
  };                      
  if (a[1] == b[1]) {
    cout << (Index(a[0]) > Index(b[0]) ? "YES" : "NO") << '\n';
    return 0;
  }
  cout << "NO" << '\n';                                              
  return 0;
}