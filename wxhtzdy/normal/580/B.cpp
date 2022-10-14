/**
 *    author:  milos
 *    created: 10.08.2021 09:20:28       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = (i == 0 ? 0 : pref[i - 1]) + a[i].second;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int bot = i, top = n - 1, pos = i;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (a[i].first + d > a[mid].first) {
        pos = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }
    ans = max(ans, pref[pos] - (i == 0 ? 0 : pref[i - 1]));
  }      
  cout << ans << '\n';  
  return 0;
}