/**
 *  author: milos
 *  created: 13.12.2020 14:29:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int h = (int) (s[0] - '0') * 10 + (int) (s[1] - '0');
  int m = (int) (s[3] - '0') * 10 + (int) (s[4] - '0');
  int n = h * 60 + m;
  auto Good = [&](int k) {
    int h = k / 60, m = k % 60;
    return (h % 10 == m / 10) && (h / 10 == m % 10);  
  };           
  for (int i = 0; i < 1440; i++) {
    if (Good(i) && n < i) {
      int h = i / 60, m = i % 60;
      if (h < 10) cout << 0;
      cout << h << ":";
      if (m < 10) cout << 0;
      cout << m << '\n';
      return 0;     
    }
  }
  cout << "00:00" << '\n';
  return 0;
}