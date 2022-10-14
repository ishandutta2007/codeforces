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
    int ans = 0 ;
    for (int i = 0; i < n; i++) {
      ans += (a[i] != a[0]);
    }
    cout << ans << '\n';
  }
  return 0;
}