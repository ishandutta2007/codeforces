/**
 *    author:  milos
 *    created: 23.03.2021 20:26:29       
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
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '4' && s[i] != '7') {
      cout << "NO" << '\n';  
      return 0;
    }
    if (i < n / 2) {
      x += (s[i] - '0');
    } else {
      y += (s[i] - '0');
    }
  }
  if (x != y) {
    cout << "NO" << '\n';
  } else cout << "YES" << '\n';
  return 0;
}