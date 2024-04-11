#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    char direction = '-';
    bool same = true;
    for (auto i : s) {
      if (i != '-') {
        if (direction == '-') {
          direction = i;
        } else {
          same &= (direction == i);
        }
      }
    }

    if (same) {
      cout << n << "\n";
      continue;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (s[i] == '-' || s[(i + 1) % n] == '-');
    }

    cout << ans << "\n";
  }
}