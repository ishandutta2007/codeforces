/**
 *    author:  tourist
 *    created: 23.11.2021 17:39:29       
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    int low = 0, high = n;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      int j = 0;
      bool ok = true;
      for (int i = 1; i <= mid; i++) {
        while (j < n && (a[j] < mid - i || b[j] < i - 1)) {
          j += 1;
        }
        if (j == n) {
          ok = false;
          break;
        }
        j += 1;
      }
      if (ok) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << low << '\n';
  }
  return 0;
}