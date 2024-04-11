#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long gcd = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    gcd = __gcd(gcd, a);
  }

  int ans = 0;
  for (long long i = 1; i * i <= gcd; ++i) {
    if (gcd % i == 0) {
      ans += 1 + (i * i < gcd);
    }
  }

  cout << ans << "\n";
}