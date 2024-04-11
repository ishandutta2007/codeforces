#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.length();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      cnt++;
    }
  }
  cout << min(n, 2 * cnt - 1);
  return 0;
}