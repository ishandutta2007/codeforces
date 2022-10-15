#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int L = 0;
  while (L < s.size() && s[L] != '[') L++;
  while (L < s.size() && s[L] != ':') L++;
  int R = s.size() - 1;
  while (R >= 0 && s[R] != ']') R--;
  while (R >= 0 && s[R] != ':') R--;
  if (L >= R) {
    cout << -1 << endl;
    exit(0);
  }
  int ans = 4;
  for (int i = L; i < R; i++) {
    ans += s[i] == '|';
  }
  cout << ans << endl;
  return 0;
}