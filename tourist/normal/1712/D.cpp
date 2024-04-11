/**
 *    author:  tourist
 *    created: 13.08.2022 17:42:42       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
    vector<int> b = a;
    sort(b.begin(), b.end());
    int low = 0, high = (int) 1e9;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      bool found = false;
      for (int i = 0; i < n - 1; i++) {
        int cnt = 0;
        if (a[i] < mid) {
          cnt += 1;
        }
        if (a[i + 1] < mid) {
          cnt += 1;
        }
        int val = (mid + 1) / 2;
        cnt += (int) (lower_bound(b.begin(), b.end(), val) - b.begin());
        if (a[i] < val) {
          cnt -= 1;
        }
        if (a[i + 1] < val) {
          cnt -= 1;
        }
        if (cnt <= k) {
          found = true;
          break;
        }
      }
      if (found) {
        low = mid;
      } else { 
        high = mid - 1;
      }
    }
    cout << low << '\n';
  }
  return 0;
}