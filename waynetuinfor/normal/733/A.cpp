#include <bits/stdc++.h>
using namespace std;

string s;
int pos = -1, Max;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
      Max = max(Max, i - pos);
      pos = i;
    }
  }
  Max = max(Max, (int)s.length() - pos);
  cout << Max << '\n';
  return 0;
}