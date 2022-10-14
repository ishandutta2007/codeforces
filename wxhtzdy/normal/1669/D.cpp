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
    string s;
    cin >> s;
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        continue;
      }
      int j = i;
      bool ok = false;
      while (j + 1 < n && s[j + 1] != 'W') {
        j += 1;
        if (s[i] != s[j]) {
          ok = true;
        }
      }
      i = j;
      if (!ok) {
        ans = false;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}