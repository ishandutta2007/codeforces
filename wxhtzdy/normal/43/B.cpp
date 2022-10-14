#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  getline(cin, s);
  getline(cin, t);
  map<char, int> cnt;
  for (int i = 0; i < (int) s.size(); i++) {
    cnt[s[i]] += 1;
  }
  for (int i = 0; i < (int) t.size(); i++) {
    if (t[i] == ' ') {
      continue;
    }
    if (cnt[t[i]] == 0) {
      cout << "NO" << '\n';
      return 0;
    }
    cnt[t[i]] -= 1;
  }
  cout << "YES" << '\n';
  return 0;
}