/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 15:36:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, b;
    long long s;
    cin >> n >> k >> b >> s;
    long long L = k * 1LL * b;
    long long R = L + n * 1LL * (k - 1);
    if (s < L || s > R) {
      cout << -1 << '\n';
      continue;
    }
    vector<long long> a(n);
    a[0] = k * 1LL * b;
    s -= a[0];
    for (int i = n - 1; i >= 0; i--) {
      long long x = min(s, k - 1LL);
      a[i] += x;
      s -= x;      
    }
    while (a[0] > 1e18) {
      a[0] -= k;
      a[1] += k;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }                                                                    
  return 0;
}