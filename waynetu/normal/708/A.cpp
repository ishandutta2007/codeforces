#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int change = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != 'a') {
      s[i]--;
      change++;
    } else {
      if (change) break;
      if (i == s.length() - 1) s[i] = 'z';
    }
  }
  cout << s << endl;
  return 0;
}