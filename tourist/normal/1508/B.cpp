/**
 *    author:  tourist
 *    created: 16.04.2021 17:41:05       
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
    k -= 1;
    vector<int> f(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      f[i] = k % 2;
      k /= 2;
    }
    if (k > 0) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> p(n);
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && f[end] == 1) {
        end += 1;
      }
      for (int i = beg; i <= end; i++) {
        p[i] = beg + end - i;
      }
      beg = end + 1;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << p[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}