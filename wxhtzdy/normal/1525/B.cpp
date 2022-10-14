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
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != i + 1) {
        ok = false;
      }
    }
    if (ok) {
      cout << 0 << '\n';
      continue;
    }
    if (a[0] == n && a[n - 1] == 1) {
      cout << 3 << '\n';
      continue;
    }
    if (a[0] == 1 || a[n - 1] == n) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}