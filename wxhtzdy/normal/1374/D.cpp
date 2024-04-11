/**
 *  author: milos
 *  created: 14.12.2020 12:33:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = k - (a[i] % k);
      a[i] %= k;
    }
    sort(a.begin(), a.end());
    int lst = -1, cnt = 0;
    long long ans = 0;             
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) continue;
      if (a[i] == lst) {
        cnt++;
        ans = max((long long) (cnt - 1) * k + a[i] + 1, ans);
      } else {
        cnt = 1, lst = a[i];
        ans = max((long long) (cnt - 1) * k + a[i] + 1, ans);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}