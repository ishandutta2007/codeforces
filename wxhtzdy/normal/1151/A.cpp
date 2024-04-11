/**
 *    author:  milos
 *    created: 25.02.2021 09:38:10       
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
  auto Solve = [&](char x, char y) {
    int ans = abs(x - y);
    return min(ans, 26 - ans);  
  };
  int ans = 200;
  for (int i = 0; i <= n - 4; i++) {
    int curr = Solve('A', s[i]);
    curr += Solve('C', s[i + 1]);
    curr += Solve('T', s[i + 2]);
    curr += Solve('G', s[i + 3]);
    ans = min(ans, curr);  
  }
  cout << ans << '\n';
  return 0;
}