/**
 *    author:  tourist
 *    created: 10.10.2021 12:13:12       
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      --a[i]; --b[i];
    }
    vector<int> ca(n), cb(n);
    for (int i = 0; i < n; i++) {
      ca[a[i]] += 1;
      cb[b[i]] += 1;
    }
    long long ans = (long long) n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++) {
      ans -= (long long) (ca[a[i]] - 1) * (cb[b[i]] - 1);
    }
    cout << ans << '\n';
  }
  return 0;
}