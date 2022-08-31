/**
 *    author:  tourist
 *    created: 10.10.2021 12:09:06       
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
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    // sum / n == sum' / (n - 2)
    __int128 goal8 = __int128(sum) * (n - 2);
    if (goal8 % n != 0) {
      cout << 0 << '\n';
      continue;
    }
    long long goal = sum - (long long) (goal8 / n);
    map<long long, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      auto it = mp.find(a[i]);
      if (it != mp.end()) {
        ans += it->second;
      }
      mp[goal - a[i]] += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}