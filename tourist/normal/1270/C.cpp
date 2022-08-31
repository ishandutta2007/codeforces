/**
 *    author:  tourist
 *    created: 29.12.2019 17:16:46       
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
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long s = 0;
    long long x = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      x ^= a[i];
    }
    cout << 2 << '\n';
    cout << x << " " << s + x << '\n';
  }
  return 0;
}