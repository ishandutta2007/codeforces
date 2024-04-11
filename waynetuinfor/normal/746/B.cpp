#include <iostream>
#include <string>
using namespace std;

int n, len;
string s, t, tmp;
char str[2005];

int main() {
  cin >> n >> s;
  len = n;
  int si = 1, mid;
  if (n & 1) mid = n / 2;
  else mid = n / 2 - 1;
  str[mid] = s[0];
  if (s.length() & 1) {
    for (int i = 1; si < s.length(); ++i) {
      str[mid - i] = s[si++];
      if (si == s.length()) break;
      str[mid + i] = s[si++];
    }
  } else {
    for (int i = 1; si < s.length(); ++i) {
      str[mid + i] = s[si++];
      if (si == s.length()) break;
      str[mid - i] = s[si++];
    }
  }
  for (int i = 0; i < len; ++i) cout << str[i];
  return 0;
}