/**
 *    author:  tourist
 *    created: 02.09.2018 17:36:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i <= n / 2; i++) {
    if (a[i] > s) {
      ans += a[i] - s;
    }
  }
  for (int i = n / 2; i < n; i++) {
    if (a[i] < s) {
      ans += s - a[i];
    }
  }
  cout << ans << '\n';
  return 0;
}