/**
 *    author:  milos
 *    created: 09.04.2021 08:27:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (char c : s) {
    a += (c == '-');
    b += (c == 'o');
  }
  cout << (b == 0 || a % b == 0 ? "YES" : "NO") << '\n';
  return 0;
}