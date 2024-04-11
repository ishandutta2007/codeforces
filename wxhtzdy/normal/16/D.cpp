/**
 *    author:  milos
 *    created: 28.01.2021 08:00:35       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int prev = 0, ans = 1;
  auto Calc = [&](char a, char b, char c, char d, char foo) {
    if (foo == 'a') {
      if (a == '1' && b == '2') {
        return (int) (c - '0') * 10 + (int) (d - '0');  
      } else {
        int t = ((int) (a - '0') * 10 + (int) (b - '0')) * 60 + (int) (c - '0') * 10 + (int) (d - '0');
        return t;
      }
    } else {
      if (a == '1' && b == '2') {
        return ((int) (a - '0') * 10 + (int) (b - '0')) * 60 + (int) (c - '0') * 10 + (int) (d - '0');
      }
      int t = ((int) (a - '0') * 10 + (int) (b - '0')) * 60 + (int) (c - '0') * 10 + (int) (d - '0');
      return t + 12 * 60;    
    }
  };
  int cnt = 0;
  for (int i = 0; i < n + 1; i++) {
    string s;
    getline(cin, s);
    if (i == 0) {
      continue;
    }
    int t = Calc(s[1], s[2], s[4], s[5], s[7]);
    if (t < prev) {
      ans += 1;
      cnt = 1;
    } else {
      if (t == prev) {
        if (cnt == 10) {
          ans += 1;
          cnt = 1;
        } else {
          cnt++;
        }
      } else {
        cnt = 1;   
      }
    }
    prev = t;
  }
  cout << ans << '\n';
  return 0;
}