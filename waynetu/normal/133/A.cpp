#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'H' || s[i] == '9' || s[i] == 'Q') {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}