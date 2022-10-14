/**
 *  author: milos
 *  created: 04.01.2021 04:25:49
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
    int mn = *min_element(a.begin(), a.end());
    vector<int> c, pos;
    for (int i = 0; i < n; i++) {
      if (a[i] % mn == 0) {
        c.push_back(a[i]);
        pos.push_back(i);  
      }
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < (int) c.size(); i++) {
      a[pos[i]] = c[i];
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}