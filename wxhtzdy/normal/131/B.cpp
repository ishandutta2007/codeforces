/**
 *  author: milos
 *  created: 13.12.2020 17:51:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  long long ans = (long long) cnt[0] * (cnt[0] - 1) / 2;
  for (int i = 1; i <= 10; i++) {
    ans += (long long) cnt[i] * cnt[-i];  
  }
  cout << ans << '\n';
  return 0;
}