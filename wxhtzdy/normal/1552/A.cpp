#include <Bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}