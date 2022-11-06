#include <iostream>
#include <string>
using namespace std;

int re[27], cnt;
string s, t;
bool v[27];

int main() {
  cin >> s >> t;
  if (s.length() != t.length()) { cout << "-1\n"; return 0; }
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != t[i]) {
      if (!re[s[i] - 'a' + 1] && !re[t[i] - 'a' + 1]) {
        re[s[i] - 'a' + 1] = t[i] - 'a' + 1;
        re[t[i] - 'a' + 1] = s[i] - 'a' + 1;
        cnt++;
      }
      else if (re[s[i] - 'a' + 1] && re[s[i] - 'a' + 1] != t[i] - 'a' + 1) { cout << "-1\n"; return 0; }
      else if (re[t[i] - 'a' + 1] && re[t[i] - 'a' + 1] != s[i] - 'a' + 1) { cout << "-1\n"; return 0; }
    } else {
      if (!re[s[i] - 'a' + 1]) re[s[i] - 'a' + 1] = s[i] - 'a' + 1;
      else if (re[s[i] - 'a' + 1] != s[i] - 'a' + 1) { cout << "-1\n"; return 0; }
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i <= 26; ++i) {
    if (v[i]) continue;
    if (re[i] && re[i] != i) {
      v[i] = v[re[i]] = true;
      cout << (char)(i + 'a' - 1) << ' ' << (char)(re[i] + 'a' - 1) << '\n';
    }
  }
  return 0;
}