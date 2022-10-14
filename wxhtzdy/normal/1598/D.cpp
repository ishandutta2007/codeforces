/**
 *    author: m371
 *    created: 10.10.2021 13:17:22
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
    vector<int> b(n);
    vector<int> cnt_a(n);
    vector<int> cnt_b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      --a[i]; --b[i];
      cnt_a[a[i]]++; cnt_b[b[i]]++;
    }
    long long ans = n * (long long) (n - 1) * (long long) (n - 2) / 6;
    for (int i = 0; i < n; i++) {
      ans -= (long long) (cnt_a[a[i]] - 1) * (long long) (cnt_b[b[i]] - 1);
    }
    cout << ans << '\n';
  }
  return 0;
}