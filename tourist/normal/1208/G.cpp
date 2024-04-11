/**
 *    author:  tourist
 *    created: 25.08.2019 18:13:14       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long ans = (long long) 9e18;
  for (int take2 = 0; take2 < 2; take2++) {
    vector<int> phi(n + 1);
    for (int i = 1; i <= n; i++) {
      phi[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + i; j <= n; j += i) {
        phi[j] -= phi[i];
      }
    }
    if (!take2) {
      for (int i = 4; i <= n; i += 2) {
        phi[i] = (int) 1e9;
      }
    }
    sort(phi.begin() + 3, phi.end());
    long long cur = 1 + take2;
    for (int i = 3; i <= k + 2; i++) {
      cur += phi[i];
    }
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}