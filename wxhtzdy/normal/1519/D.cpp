/**
 *    author:  milos
 *    created: 29.04.2021 19:46:03       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i] * b[i];
  }
  long long ans = sum;
  for (int i = 0; i < n; i++) {
    long long nans = sum;
    int l = i - 1, r = i + 1;
    while (l >= 0 && r < n) {
      nans -= a[l] * b[l];
      nans -= a[r] * b[r];
      nans += a[l] * b[r];
      nans += a[r] * b[l];
      ans = max(ans, nans);
      --l; ++r;
    }
  }
  for (int i = 0; i < n; i++) {
    long long nans = sum;
    int l = i, r = i + 1;
    while (l >= 0 && r < n) {
      nans -= a[l] * b[l];
      nans -= a[r] * b[r];
      nans += a[l] * b[r];
      nans += a[r] * b[l];
      ans = max(ans, nans);
      --l; ++r;
    }
  }
  cout << ans << '\n';
  return 0;
}