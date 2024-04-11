/**
 *    author:  tourist
 *    created: 20.06.2021 13:54:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k, x;
  cin >> n >> k >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    b[i] = max(0LL, (a[i + 1] - a[i] - 1) / x);
  }
  sort(b.begin(), b.end());
  int ans = n;
  for (int i = 0; i < n - 1; i++) {
    if (b[i] <= k) {
      k -= b[i];
      ans -= 1;
    }
  }
  cout << ans << '\n';
  return 0;
}