#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(26);
    for (int i = 0; i < 2 * n + 1; i++) {
      string s;
      cin >> s;
      for (char c : s) {
        cnt[c - 'a'] += 1;
      }
    }
    int f = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        f = i;
      }
    }
    cout << (char) ('a' + f) << '\n';
  }
  return 0;
}