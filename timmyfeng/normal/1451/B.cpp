#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    string s;
    cin >> n >> q >> s;

    while (q--) {
      int a, b;
      cin >> a >> b;

      bool ok = false;
      for (int i = 0; i < a - 1; ++i) {
        ok |= s[i] == s[a - 1];
      }
      for (int i = b; i < n; ++i) {
        ok |= s[i] == s[b - 1];
      }

      cout << (ok ? "YES" : "NO") << "\n";
    }
  }
}