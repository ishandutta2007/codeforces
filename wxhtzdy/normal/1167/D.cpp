/**
 *    author:  milos
 *    created: 21.09.2021 11:17:59       
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
  int bal = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      cout << bal % 2;
      bal++;
    }
    if (s[i] == ')') {
      cout << 1 - bal % 2;
      bal--;
    }
  }
  cout << '\n';
  return 0;
}