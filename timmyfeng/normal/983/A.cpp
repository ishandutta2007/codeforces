#include <bits/stdc++.h>
using namespace std;

const long long O = 2e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    long long p, q, b;
    cin >> p >> q >> b;
    q /= __gcd(p, q);

    while (min(b, q) > 1) {
      while (q % b == 0) {
        q /= b;
      }
      b = __gcd(q, b);
    }

    cout << (q == 1 ? "Finite" : "Infinite") << "\n";
  }
}