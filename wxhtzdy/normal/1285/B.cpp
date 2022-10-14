/**
 *  author: milos
 *  created: 13.01.2021 19:19:22
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
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    bool ok = true;
    set<pair<long long, int>> b;
    b.insert({0, 0});
    long long bal = 0ll;
    for (int i = 0; i < n; i++) {
      bal += a[i];
      if (i < n - 1) {
        if ((bal - b.begin()->first) >= sum) {
          ok = false;
        }
      } else {                    
        if (n == 2) {
          continue;
        }    
        if (b.begin()->second == 0) {
          b.erase(b.begin());    
        }
        if (bal - b.begin()->first >= sum) {
          ok = false;
        }
      }
      b.insert({bal, i});
    }
    if (n == 2 && a[1] >= a[0] + a[1]) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}