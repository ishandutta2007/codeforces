/**
 *    author:  tourist
 *    created: 18.06.2020 17:51:28       
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
  vector<long long> b(n);
  for (int bit = 0; bit < 20; bit++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += ((a[i] >> bit) & 1);
    }
    for (int i = 0; i < cnt; i++) {
      b[i] |= 1 << bit;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += b[i] * b[i];
  }
  cout << ans << '\n';
  return 0;
}