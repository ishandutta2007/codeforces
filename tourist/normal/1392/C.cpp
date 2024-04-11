/**
 *    author:  tourist
 *    created: 16.08.2020 17:37:38       
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
      d[i] = a[i + 1] - a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += max(-d[i], 0);
    }
    cout << ans << '\n';
  }
  return 0;
}