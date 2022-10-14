#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, c;
    cin >> n >> c;
    vector<int> a(n); 
    vector<bool> have(c + 1, false);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      have[a[i]] = true;
    }                   
    vector<int> pref(c + 1);
    for (int i = 1; i <= c; i++) {
      pref[i] = pref[i - 1] + have[i];
    }
    bool ok = true;
    for (int i = 1; i <= c; i++) {
      if (have[i]) {
        continue;
      }
      for (int y = 1; i * 1ll * y <= c; y++) {
        if (!have[y]) {
          continue;
        }
        int l = i * y;
        int r = min(c, (i + 1) * y - 1);
        if (pref[r] > pref[l - 1]) {
          ok = false;
        }
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }                                                                    
  return 0;
}