/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 21:37:57
**/
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]] += 1;
      if (mp[a[i]] <= 3) {
        b.push_back(a[i]);
      }
    }
    a = b;
    n = (int) a.size();
    set<int> st = set<int>(a.begin(), a.end());
    bool ok = false;
    sort(a.begin(), a.end());
    for (int i = 0; i < min(n, 10); i++) {
      for (int j = i + 1; j < min(n, 10); j++) {
        for (int k = j + 1; k < min(n, 10); k++) {
          int sum = a[i] + a[j] + a[k];
          if (st.find(sum) == st.end()) {
            ok = true;
          }
        }
      }
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < min(n, 10); i++) {
      for (int j = i + 1; j < min(n, 10); j++) {
        for (int k = j + 1; k < min(n, 10); k++) {
          int sum = a[i] + a[j] + a[k];
          if (st.find(sum) == st.end()) {
            ok = true;
          }
        }
      }
    }
    cout << (ok ? "NO" : "YES") << '\n';
  }
  return 0;
}