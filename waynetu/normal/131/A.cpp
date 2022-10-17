#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool on = true;
  if (s[0] >= 'a') {
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] >= 'a') on = false;
    }
    if (on) {
      cout << (char)(s[0] - 32);
      for (int i = 1; i < s.length(); ++i) {
        cout << (char)(s[i] + 32);
      }
      cout << endl;
    } else {
      cout << s << endl;
    }
  } else {
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] >= 'a') on = false;
    }
    if (on) {
      for (int i = 0; i < s.length(); ++i) {
        cout << (char)(s[i] + 32);
      }
      cout << endl;
    } else {
      cout << s << endl;
    }
  }
  return 0;
}