/**
 *    author:  tourist
 *    created: 12.05.2020 15:50:55       
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
    vector<int> a(n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = (a[i] < k ? -1 : (a[i] > k ? 1 : 0));
      zeros += (a[i] == 0);
    }
    if (zeros == 0) {
      cout << "no" << '\n';
      continue;
    }
    if (zeros == n) {
      cout << "yes" << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      ok |= (a[i] >= 0 && a[i + 1] >= 0);
    }
    for (int i = 0; i < n - 2; i++) {
      ok |= (a[i] >= 0 && a[i + 2] >= 0);
    }
    cout << (ok ? "yes" : "no") << '\n';
  }
  return 0;
}