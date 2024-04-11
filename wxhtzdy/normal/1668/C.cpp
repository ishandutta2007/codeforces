#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }           
  long long ans = 1e18;
  for (int i = 0; i < n; i++) {
    long long nans = 0;
    long long prv = 0;
    for (int j = i + 1; j < n; j++) {
      long long delta = prv / a[j];
      while (delta * a[j] <= prv) {
        delta++;
      }
      prv = delta * a[j];
      nans += delta;
    }
    prv = 0;              
    for (int j = i - 1; j >= 0; j--) {
      long long delta = prv / a[j];
      while (delta * a[j] <= prv) {
        delta++;
      }
      prv = delta * a[j];
      nans += delta;
    }
    ans = min(ans, nans);
  }
  cout << ans << '\n';
  return 0;
}