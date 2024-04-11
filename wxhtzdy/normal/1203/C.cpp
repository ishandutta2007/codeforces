#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long g = a[0];
  for (int i = 1; i < n; i++) {
    g = __gcd(g, a[i]);
  }
  long long ans = 0;
  for (long long i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      ans += 1;
      if (i * i != g) {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}