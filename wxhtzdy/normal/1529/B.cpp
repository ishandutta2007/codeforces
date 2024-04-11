#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = n, mn = 2e9;
    for (int i = 1; i < n; i++) {
      mn = min(mn, a[i] - a[i - 1]);
      if (mn < a[i]) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}