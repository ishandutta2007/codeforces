#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      if ((i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2])) {
        s[i] = 0;
        ++ans;
      }
    }
    cout << ans << "\n";
  }
}