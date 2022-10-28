#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int len = 0;
    char cur = s[0];
    while (!s.empty() && s.back() == cur) {
      s.pop_back();
      ++len;
    }

    if (s.empty()) {
      cout << (len + 2) / 3 << "\n";
      continue;
    }

    int ans = 0;
    for (char c : s) {
      if (c != cur) {
        ans += len / 3;
        cur = c;
        len = 0;
      }
      ++len;
    }

    ans += len / 3;
    cout << ans << "\n";
  }
}