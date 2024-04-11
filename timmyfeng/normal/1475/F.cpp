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

    vector<string> s(n), t(n);
    for (auto &i : s) {
      cin >> i;
    }
    for (auto &i : t) {
      cin >> i;
    }

    for (int i = 0; i < n; ++i) {
      if (s[i][0] != t[i][0]) {
        for (auto &i : s[i]) {
          i ^= '0' ^ '1';
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (s[0][i] != t[0][i]) {
        for (int j = 0; j < n; ++j) {
          s[j][i] ^= '0' ^ '1';
        }
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= (s[i] == t[i]);
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}