/**
 *    author:  milos
 *    created: 23.03.2021 08:47:24       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    cout << (s[i] != t[i] ? 1 : 0);
  }
  return 0;
}