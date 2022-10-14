#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    map<char, int> was;
    int cnt = 0;
    for (int j = i; j < n; j++) {
      if (s[j] < 'a') {
        break;
      }
      if (!was[s[j]]) {
        cnt++;
      }
      ans = max(ans, cnt);
      was[s[j]] = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}