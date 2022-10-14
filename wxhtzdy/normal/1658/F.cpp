#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        pref[i] = pref[i - 1];
      }
      pref[i] += (s[i] == '1');
    }
    int cc = pref.back();
    long long p = cc * 1LL * m;
    if (p % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    p /= n;
    int idx = -1;
    for (int i = 0; i + m <= n; i++) {
      int tot = pref[i + m - 1];
      if (i > 0) {
        tot -= pref[i - 1];
      }                 
      if (tot == p) {
        idx = i;
      }
    }
    if (idx != -1) {
      cout << 1 << '\n';
      cout << idx + 1 << " " << idx + m << '\n';
      continue;
    }
    for (int i = 1; i < m; i++) {
      int tot = pref[i - 1] + pref[n - 1] - pref[n - (m - i) - 1];
      if (tot == p) {
        idx = i;
      }
    }
    cout << 2 << '\n';
    cout << 1 << " " << idx << '\n';
    cout << n - (m - idx) + 1 << " " << n << '\n';
  }                                                                    
  return 0;
}