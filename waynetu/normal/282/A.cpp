#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int n;
  cin >> n;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s[0] == '+' || s[2] == '+') x++;
    else x--;
  }
  cout << x << endl;
  return 0;
}