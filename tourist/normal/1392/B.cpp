/**
 *    author:  tourist
 *    created: 16.08.2020 17:36:14       
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
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long it = 1; it <= k; it++) {
      int mx = *max_element(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        a[i] = mx - a[i];
      }
      if (it % 2 == k % 2) {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }
  return 0;
}