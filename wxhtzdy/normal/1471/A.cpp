/**
 *  author: milos
 *  created: 05.01.2021 15:35:41
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
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    long long sum = 0, r = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      r += (a[i] + x - 1) / x;
    }
    sum = (sum + x - 1) / x;
    cout << min(sum, r) << " " << max(sum, r) << '\n';
  }
  return 0;
}