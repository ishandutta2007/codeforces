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
    vector<bool> was(26);
    string t = "";
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (was[c]) {
        break;
      }
      was[c] = true;
      t += s[i];
    }
    bool ok = true;
    int m = t.size();
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i % m]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}