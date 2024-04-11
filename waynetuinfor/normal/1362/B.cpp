#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<bool> vis(1024);
    for (int i = 0; i < n; ++i) vis[s[i]] = true;
    int res = 1024;
    for (int i = 1; i < n; ++i) {
      int x = s[0] ^ s[i];
      bool ok = true;
      for (int j = 0; j < n; ++j) ok &= vis[s[j] ^ x];
      if (ok) {
        res = min(res, x);
      }
    }
    if (res == 1024) res = -1;
    cout << res << "\n";
  }
}