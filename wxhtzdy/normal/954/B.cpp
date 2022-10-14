/**
 *    author:  milos
 *    created: 02.04.2021 00:04:04       
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
  for (int i = 1; i <= n / 2; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (s[j] != s[i + j]) {
        ok = false;
      }
    }
    if (ok) {
      ans = i - 1;
    }
  }
  cout << n - ans << '\n';
  return 0;
}