#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int one = 0, zero = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (one >= 7 || zero >= 7) {
      cout << "YES" << endl;
      return 0;
    }
    if (s[i] == '1') {
      zero = 0;
      one++;
    } else {
      zero++;
      one = 0;
    }
  }
  if (one >= 7 || zero >= 7) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}