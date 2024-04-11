/**
 *    author:  milos
 *    created: 17.03.2021 07:36:24       
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
    bool a = false, b = false;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && (int) (s[i] - '0') % 2 == 1) {
        a = true;
      }
      if (i % 2 == 1 && (int) (s[i] - '0') % 2 == 0) {
        b = true;
      }
    }
    if (n % 2 == 0) {
      cout << (b ? 2 : 1) << '\n';
    } else {
      if (n % 2 == 1) {
        cout << (a ? 1 : 2) << '\n';  
      }
    }
  }
  return 0;
}