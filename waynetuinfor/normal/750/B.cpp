#include <iostream>
#include <string>
using namespace std;

int n, l, pos;
string s;

int main() {
  cin >> n;
  pos = 0;
  while (n--) {
    cin >> l >> s;
    if (!pos && s[0] != 'S') { cout << "NO\n"; return 0; }
    if (pos == 20000 && s[0] != 'N') { cout << "NO\n"; return 0; }
    if (s[0] == 'N') {
      pos -= l;
      if (pos < 0) { cout << "NO\n"; return 0; }
    }
    if (s[0] == 'S') {
      pos += l;
      if (pos > 20000) { cout << "NO\n"; return 0; }
    }
  }
  if (pos != 0) { cout << "NO\n"; return 0; }
  cout << "YES\n";
  return 0;
}