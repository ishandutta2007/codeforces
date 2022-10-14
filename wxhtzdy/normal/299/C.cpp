/**
 *    author:  wxhtzdy
 *    created: 24.08.2022 21:24:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int c01 = 0, c10 = 0, c11 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0' && t[i] == '0') {
      continue;
    }
    if (s[i] == '0') {
      c01 += 1;
      continue;
    }
    if (t[i] == '0') {
      c10 += 1;
      continue;
    }
    c11 += 1;
  }
  int turn = 0;
  int c0 = 0;
  int c1 = 0;                       
  while (c01 + c10 + c11 > 0) {
    if (turn == 0) {
      if (c11 > 0) {
        c0 += 1;
        c11 -= 1;  
      } else if (c10 > 0) {
        c0 += 1;
        c10 -= 1;
      } else {
        c01 -= 1;
      }
    } else {
      if (c11 > 0) {
        c1 += 1;
        c11 -= 1;  
      } else if (c01 > 0) {
        c1 += 1;
        c01 -= 1;
      } else {
        c10 -= 1;
      }
    }
    turn ^= 1;
  }
  cout << (c0 > c1 ? "First" : (c0 == c1 ? "Draw" : "Second")) << '\n';                                                          
  return 0;
}