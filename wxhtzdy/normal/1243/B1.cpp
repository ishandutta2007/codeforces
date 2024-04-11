/**
 *    author:  milos
 *    created: 28.01.2021 01:54:59       
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
    string s, t;
    cin >> s >> t;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        pos.push_back(i);
      }
    }                
    if ((int) pos.size() != 2) {
      cout << "No" << '\n';
    } else {
      char x = s[pos[0]];
      char y = s[pos[1]];
      char xx = t[pos[0]];
      char yy = t[pos[1]];
      if (x != y || xx != yy) {
        cout << "No" << '\n';
      } else {
        cout << "Yes" << '\n';
      }
    }
  }
  return 0;
}