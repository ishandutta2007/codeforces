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
  sort(a.rbegin(), a.rend());
  int j = 1e9, ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] + 1 < j) {
      j = a[i] + 1;
      ans += 1;
    } else {
      if (a[i] < j) {
        j = a[i];
        ans += 1;
      } else {
        if (a[i] - 1 < j && a[i] - 1 > 0) {
          j = a[i] - 1;
          ans += 1;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}