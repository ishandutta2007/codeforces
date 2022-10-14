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
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if ((i == 0 || s[i] != s[i - 1]) && (i == n - 1 || s[i] != s[i + 1])) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}