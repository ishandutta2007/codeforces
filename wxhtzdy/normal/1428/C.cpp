#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    deque<char> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
        q.push_back(s[i]);
      } else {
        if (!q.empty()) {
          q.pop_back();
          ans += 2;
        } else {
          q.push_back(s[i]);
        }
      }
    }
    cout << n - ans << '\n';
  }
  return 0;
}