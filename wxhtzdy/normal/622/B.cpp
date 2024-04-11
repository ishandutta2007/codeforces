#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s;
  cin >> s;
  int h = (s[0] - '0') * 10 + (s[1] - '0');
  int m = (s[3] - '0') * 10 + (s[4] - '0');                                                                      
  int a;
  cin >> a;    
  m += a;
  h += (m / 60);
  m %= 60;
  h %= 24; 
  if (h < 10) {
    cout << 0;
  }
  cout << h;
  cout << ':';
  if (m < 10) {
    cout << 0;
  }
  cout << m;
  return 0;
}