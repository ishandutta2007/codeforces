/**
 *    author:  tourist
 *    created: 12.05.2020 15:34:45       
**/
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
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = __gcd(pref[i], a[i]);
  }
  vector<int> suf(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = __gcd(suf[i + 1], a[i]);
  }
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    int x = __gcd(pref[i], suf[i + 1]);
    ans = ans / __gcd(ans, (long long) x) * x;
  }
  cout << ans << '\n';
  return 0;
}