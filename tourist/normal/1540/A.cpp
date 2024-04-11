/**
 *    author:  tourist
 *    created: 25.06.2021 18:30:49       
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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    sort(d.begin(), d.end());
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      ans -= (long long) i * d[i] - sum;
      sum += d[i];
    }
    ans += *max_element(d.begin(), d.end());
    cout << ans << '\n';
  }
  return 0;
}