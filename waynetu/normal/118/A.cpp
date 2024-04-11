#include <iostream>
#include <string>
using namespace std;

char vowels[12] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};

bool v(char c) {
  for (int i = 0; i < 12; ++i) {
    if (c == vowels[i]) return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  string ret = "";
  for (int i = 0; i < s.length(); ++i) {
    if (!v(s[i])) {
      ret += '.';
      if (s[i] < 97)
        ret += (char)s[i] + 32;
      else
        ret += s[i];
    }
  }
  cout << ret << endl;
  return 0;
}