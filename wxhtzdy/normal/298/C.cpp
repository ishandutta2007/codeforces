/**
 *    author:  milos
 *    created: 24.03.2021 10:57:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int cnt1 = 0, cnt2 = 0;
  for (char c : s) cnt1 += (c == '1');
  for (char c : t) cnt2 += (c == '1');
  if (cnt1 & 1) {
    cnt1 += 1;
  }
  cout << (cnt1 >= cnt2 ? "YES" : "NO") << '\n';
  return 0;
}