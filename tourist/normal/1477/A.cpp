/**
 *    author:  tourist
 *    created: 28.01.2021 17:26:07       
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
    long long k;
    cin >> n >> k;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x.begin(), x.end());
    long long g = 0;
    for (int i = 0; i < n - 1; i++) {
      g = __gcd(g, x[i + 1] - x[i]);
    }
    cout << ((k - x[0]) % g == 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}