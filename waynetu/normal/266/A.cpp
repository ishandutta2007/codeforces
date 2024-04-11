#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  int i = 0;
  while (i < s.length()) {
    if (s[i] == s[i + 1]) {
      cnt++;
    }
    i++;
  }
  cout << cnt << endl;
  return 0;
}