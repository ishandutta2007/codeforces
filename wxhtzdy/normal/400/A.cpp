/**
 *    author:  milos
 *    created: 08.02.2021 10:51:16       
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
    vector<pair<int, int>> ans;
    for (int a = 1; a <= 12; a++) {
      if (12 % a != 0) {
        continue;
      }
      int b = 12 / a;            
      for (int i = 0; i < b; i++) {
        bool ok = true;
        for (int j = i; j < 12; j += b) {
          if (s[j] != 'X') {
            ok = false;
          }
        }
        if (ok) {
          ans.emplace_back(a, b);
          break;
        }
      }
    }
    cout << (int) ans.size() << " " ;
    for (auto c : ans) {
      cout << c.first << "x" << c.second << " ";
    }
    cout << '\n';
  }
  return 0;
}