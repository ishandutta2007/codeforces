/**
 *  author: milos
 *  created: 15.12.2020 15:56:37
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
    map<int, int> suff;
    map<int, int> pref;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      suff[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      suff[a[i]]--;
      ans += (long long) pref[a[i]] * suff[a[i]];
      ans += (long long) pref[a[i] - 1] * suff[a[i]];
      ans += (long long) pref[a[i]] * suff[a[i] - 1];
      ans += (long long) pref[a[i] + 1] * suff[a[i]];
      ans += (long long) pref[a[i]] * suff[a[i] + 1];
      ans += (long long) pref[a[i] - 1] * suff[a[i] + 1];
      ans += (long long) pref[a[i] + 1] * suff[a[i] - 1];
      ans += (long long) pref[a[i]] * suff[a[i] + 2];
      ans += (long long) pref[a[i] + 2] * suff[a[i]];
      ans += (long long) pref[a[i]] * suff[a[i] - 2];
      ans += (long long) pref[a[i] - 2] * suff[a[i]];

      ans += (long long) pref[a[i] - 1] * suff[a[i] - 1];
      ans += (long long) pref[a[i] - 2] * suff[a[i] - 1];
      ans += (long long) pref[a[i] - 1] * suff[a[i] - 2];
      ans += (long long) pref[a[i] - 2] * suff[a[i] - 2];

      ans += (long long) pref[a[i] + 1] * suff[a[i] + 1];
      ans += (long long) pref[a[i] + 2] * suff[a[i] + 1];
      ans += (long long) pref[a[i] + 1] * suff[a[i] + 2];
      ans += (long long) pref[a[i] + 2] * suff[a[i] + 2];
      pref[a[i]]++;
    }
    cout << ans << '\n';
  }
  return 0;
}