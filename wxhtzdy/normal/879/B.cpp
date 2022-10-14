#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= k) {
    sort(a.begin(), a.end());
    cout << a[n - 1] << '\n';
    return 0;
  }
  int mx = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < mx) {
      cnt++;
      if (cnt == k) {
        cout << mx << '\n';
        return 0;
      }
    } else {
      mx = a[i];
      if (i == 0) cnt = 0;
      else cnt = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < mx) {
      cnt++;
      if (cnt == k) {
        cout << mx << '\n';
        return 0;
      }
    } else {
      mx = a[i];
      cnt = 1;
    }
  }
  return 0;
}