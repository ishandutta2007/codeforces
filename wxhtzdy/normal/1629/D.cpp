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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      bool is = true;
      int len = s[i].size();
      for (int j = 0; j < s[i].size(); j++) {
        if (s[i][j] != s[i][len - j - 1]) {
          is = false;
        }
      }
      if (is) {
        ok = true;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
      continue;
    }
    map<string, bool> have;
    for (int i = 0; i < n; i++) {
      string t = s[i];
      reverse(t.begin(), t.end());
      if (have[t]) {
        ok = true;
        break;
      }
      have[s[i]] = true;
    }
    if (ok) {
      cout << "YES" << '\n';
      continue;
    }
    have.clear();
    for (int i = 0; i < n; i++) {
      if ((int) s[i].length() == 3) {
        string t = "";
        t += s[i][2];
        t += s[i][1];
        if (have[t]) {
          ok = true;
          break;
        }
      }
      have[s[i]] = true;
    }
    have.clear();
    for (int i = n - 1; i >= 0; i--) {
      if ((int) s[i].length() == 3) {
        string t = "";
        t += s[i][1];
        t += s[i][0];
        if (have[t]) {
          ok = true;
        }
      }
      have[s[i]] = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}