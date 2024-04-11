#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 1;

int sieve[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < N; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < N; j += i) {
        sieve[j] = i;
      }
    }
  }

  int n, k;
  cin >> n >> k;

  map<int, int> gcd;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    while (c > 1) {
      int p = sieve[c], a = 0;
      while (c % p == 0) {
        c /= p;
        ++a;
      }
      gcd[p] = max(gcd[p], a);
    }
  }

  for (auto [p, a] : gcd) {
    for (int i = 0; i < a; ++i) {
      if (k % p == 0) {
        k /= p;
      }
    }
  }

  cout << (k == 1 ? "Yes" : "No") << "\n";
}