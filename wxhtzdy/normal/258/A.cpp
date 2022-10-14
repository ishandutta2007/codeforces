#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  int pos = n - 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      pos = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (pos != i) {
      cout << s[i];
    }
  }
  return 0;
}