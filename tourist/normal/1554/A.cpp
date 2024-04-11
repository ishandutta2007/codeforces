/**
 *    author:  tourist
 *    created: 07.08.2021 15:46:41       
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
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, (long long) a[i] * a[i + 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}