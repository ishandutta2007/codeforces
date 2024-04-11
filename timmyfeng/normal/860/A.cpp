#include <bits/stdc++.h>
using namespace std;

bool vowel(char c) {
  for (auto i : "aeiou") {
    if (i == c) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int prv = 0;
  for (int i = 0; i + 2 < int(s.size()); ++i) {
    if (s[i] != s[i + 1] || s[i] != s[i + 2]) {
      if (!vowel(s[i]) && !vowel(s[i + 1]) && !vowel(s[i + 2])) {
        cout << s.substr(prv, i + 2 - prv) << " ";
        prv = i + 2;
        ++i;
      }
    }
  }
  cout << s.substr(prv) << "\n";
}