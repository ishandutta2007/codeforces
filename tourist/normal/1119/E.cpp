/**
 *    author:  tourist
 *    created: 06.04.2019 12:45:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  long long pairs = 0;
  for (int i = n - 1; i >= 0; i--) {
    pairs += a[i] / 2;
    if (a[i] % 2 == 1 && pairs > 0) {
      ans += 1;
      pairs -= 1;
    }
  }
  ans += 2 * pairs / 3;
  cout << ans << '\n';
  return 0;
}