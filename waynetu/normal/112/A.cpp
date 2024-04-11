#include <string>
#include <iostream>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.length(); ++i) {
    char c1, c2;
    if (s1[i] < 97) {
      c1 = s1[i] + 32;
    } else {
      c1 = s1[i];
    }
    if (s2[i] < 97) {
      c2 = s2[i] + 32;
    } else {
      c2 = s2[i];
    }
    if (c1 > c2) {
      cout << 1 << endl;
      return 0;
    } else if (c1 < c2) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}