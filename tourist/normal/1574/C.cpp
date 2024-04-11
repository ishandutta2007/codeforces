/**
 *    author:  tourist
 *    created: 20.09.2021 17:39:11       
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
  sort(a.begin(), a.end());
  long long total = accumulate(a.begin(), a.end(), 0LL);
  int q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    long long ans = (long long) 9e18;
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it != a.end()) {
      long long have = total - (*it);
      long long add = max(0LL, y - have);
      ans = min(ans, add);
    }
    if (it != a.begin()) {
      long long have = total - (*prev(it));
      long long add = max(0LL, y - have);
      add += x - (*prev(it));
      ans = min(ans, add);
    }
    cout << ans << '\n';
  }
  return 0;
}