#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string t;
  cin >> t;
  swap(s, t);
  int n = (int) s.size(), k = (int) t.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j < k && t[j] == s[i]) {
      j++;
    }
  }
  cout << j + 1 << '\n';
  return 0;
}