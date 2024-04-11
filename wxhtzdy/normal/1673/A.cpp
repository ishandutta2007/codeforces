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
    int n = s.size();
    int score = 0;
    for (int i = 0; i < n; i++) {
      score += (s[i] - 'a' + 1);
    }
    if (n == 1) {
      cout << "Bob " << score << '\n';
    } else {
      if (n & 1) {
        score -= (min(s[0], s[n - 1]) - 'a' + 1) * 2;
      }
      cout << "Alice " << score << '\n';
    }
  }
  return 0;
}