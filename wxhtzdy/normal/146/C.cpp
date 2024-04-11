/**
 *    author:  milos
 *    created: 23.03.2021 20:34:04       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = (int) s.size();
  vector<int> ans(2, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '4' && t[i] == '7') {
      ans[0] += 1;
    }
    if (s[i] == '7' && t[i] == '4') {
      ans[1] += 1;
    }
  }
  cout << max(ans[0], ans[1])   << '\n';
  return 0;
}