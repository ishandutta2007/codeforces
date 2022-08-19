/**
 *    author:  tourist
 *    created: 30.09.2020 17:37:34       
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int diff = 1;
    for (int i = 1; i < n; i++) {
      diff += (a[i] != a[i - 1]);
    }
    if (k == 1) {
      cout << (diff == 1 ? 1 : -1) << '\n';
      continue;
    }
    cout << max(1, (diff - 1 + (k - 2)) / (k - 1)) << '\n';
  }
  return 0;
}