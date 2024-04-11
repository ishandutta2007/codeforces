/**
 *    author:  tourist
 *    created: 07.02.2019 16:37:03       
**/
#include <bits/stdc++.h>

using namespace std;
               
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n - 1; i++) {
    b.push_back(a[i + 1] - a[i] - 1);
  }
  sort(b.rbegin(), b.rend());
  int ans = a[n - 1] - a[0] + 1;
  for (int i = 0; i < k - 1; i++) {
    ans -= b[i];
  }
  cout << ans << '\n';
  return 0;
}