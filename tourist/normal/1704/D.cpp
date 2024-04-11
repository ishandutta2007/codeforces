/**
 *    author:  tourist
 *    created: 31.07.2022 17:16:43       
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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      long long sum = 0;
      for (int j = 0; j < m; j++) {
        long long x;
        cin >> x;
        sum += x * j;
      }
      a[i] = sum;
    }
    int id = (int) (max_element(a.begin(), a.end()) - a.begin());
    cout << id + 1 << " " << a[id] - a[(id + 1) % n] << '\n';
  }
  return 0;
}