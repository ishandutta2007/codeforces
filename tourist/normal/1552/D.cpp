/**
 *    author:  tourist
 *    created: 25.07.2021 17:41:17       
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
    int p3 = 1;
    for (int i = 0; i < n; i++) {
      p3 *= 3;
    }
    bool found = false;
    for (int t = 1; t < p3; t++) {
      int tmp = t;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        int d = tmp % 3;
        if (d == 1) sum += a[i];
        if (d == 2) sum -= a[i];
        tmp /= 3;
      }
      if (sum == 0) {
        found = true;
        break;
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}