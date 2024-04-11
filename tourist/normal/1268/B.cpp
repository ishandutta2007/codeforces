/**
 *    author:  tourist
 *    created: 21.12.2019 14:08:24       
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
  vector<long long> cnt(2, 0);
  for (int i = 0; i < n; i++) {
    cnt[i % 2] += a[i] / 2;
    cnt[(i + 1) % 2] += (a[i] + 1) / 2;
  }
  cout << min(cnt[0], cnt[1]) << '\n';
  return 0;
}