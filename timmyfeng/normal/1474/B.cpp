#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> primes;
  for (int i = 2; i <= 30000; ++i) {
    bool ok = true;
    for (int j = 2; j * j <= i && ok; ++j) {
      ok &= (i % j != 0);
    }

    if (ok) {
      primes.insert(i);
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int d;
    cin >> d;

    long long p = *primes.lower_bound(d + 1);
    long long q = *primes.lower_bound(d + p);

    cout << min(p * p * p, p * q) << "\n";
  }
}