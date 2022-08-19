/**
 *    author:  tourist
 *    created: 19.12.2020 12:31:44       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long g = 0;
  for (int i = 1; i < n; i++) {
    g = __gcd(g, abs(a[i] - a[0]));
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << __gcd(g, a[0] + b[i]);
  }
  cout << '\n';
  return 0;
}