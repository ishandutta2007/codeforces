#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, bool> have;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      have[a[i]] = true;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (have[a[i] - k]) {
        ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}