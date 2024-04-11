/**
 *  author: milos
 *  created: 15.12.2020 15:35:17
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
    map<int, int> was;
    for (int i = 0; i < n; i++) {
      if (was[i] == 0) cout << a[i] << " ";
      was[i] = 1;
      if (was[n - i - 1] == 0) {
        cout << a[n - i - 1] << " ";
      }
      was[i] = 1;
      was[n - i - 1] = 1;
    }
    cout << '\n';
  }
  return 0;
}