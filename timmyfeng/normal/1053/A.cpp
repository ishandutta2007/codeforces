#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m, k;
  cin >> n >> m >> k;

  bool ok = false;
  if (k % 2 == 0) {
    k /= 2;
    ok = true;
  }

  long long r = n / __gcd(n, k);
  k /= __gcd(n, k);
  long long c = m / __gcd(m, k);
  k /= __gcd(m, k);

  if (!ok) {
    if (r * 2 <= n) {
      r *= 2;
    } else {
      c *= 2;
    }
  }

  if (k == 1) {
    cout << "YES\n";
    cout << 0 << " " << 0 << "\n";
    cout << r << " " << 0 << "\n";
    cout << 0 << " " << c << "\n";
  } else {
    cout << "NO\n";
  }
}