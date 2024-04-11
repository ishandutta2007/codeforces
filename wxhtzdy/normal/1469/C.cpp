/**
 *  author: milos
 *  created: 08.01.2021 20:07:13
**/
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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<int> l(n);
    vector<int> r(n);
    l[0] = r[0] = h[0];
    bool ok = true;
    for (int i = 1; i < n; i++) {
      l[i] = max(l[i - 1] - k + 1, h[i]);
      r[i] = min(r[i - 1] + k - 1, h[i] + k - 1);
      if (l[i] > r[i]) {
        ok = false;
      }
    }
    if (l[n - 1] > h[n - 1] || r[n - 1] < h[n - 1]) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}