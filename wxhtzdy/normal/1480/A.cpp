/**
 *    author:  milos
 *    created: 07.02.2021 15:35:38       
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
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (s[i] == 'a') {
          cout << 'b';
        } else {
          cout << 'a';
        }
      } else {
        if (s[i] == 'z') {
          cout << (char) ('z' - 1);
        } else {
          cout << 'z';
        }
      }
    }
    cout << '\n';  
  }
  return 0;
}