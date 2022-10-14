/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:33:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s.back() == t.back()) {
      if (s == t) {
        cout << "=" << '\n';
        continue;
      }
      if (s.back() == 'S') {
        cout << (s.size() < t.size() ? ">" : "<") << '\n';
      } else {
        cout << (s.size() > t.size() ? ">" : "<") << '\n';
      }
    } else {
      if (s.back() == 'S') {
        cout << "<" << '\n';
      } else if (s.back() == 'L') {
        cout << ">" << '\n';
      } else if (t.back() == 'S') {
        cout << ">" << '\n';
      } else {
        cout << "<" << '\n';
      }
    }
  }                                                                    
  return 0;
}