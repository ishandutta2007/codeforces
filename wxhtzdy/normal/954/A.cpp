/**
 *    author:  milos
 *    created: 01.04.2021 23:57:47       
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
  int ans = 0;
  char c = 'a';
  for (int i = 0; i < n; i++) {
    if ((s[i] == 'U' && c == 'R') || (s[i] == 'R' && c == 'U')) {
      c = 'D';
      ans += 1;
    } else {
      c = s[i];
    }
  }
  cout << n - ans << '\n';
  return 0;
}