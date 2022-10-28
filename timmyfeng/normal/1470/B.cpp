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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<int, int> count;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      int b = 1;
      while (a > 1) {
        int p = sieve[a], c = 0;
        while (a % p == 0) {
          a /= p;
          ++c;
        }
        if (c % 2 == 1) {
          b *= p;
        }
      }
      ++count[b];
    }

    int even = 0, all = 0;
    for (auto [a, b] : count) {
      if (b % 2 == 0 || a == 1) {
        even += b;
      }
      all = max(all, b);
    }

    int q;
    cin >> q;

    while (q--) {
      long long w;
      cin >> w;
      if (w == 0) {
        cout << all << "\n";
      } else {
        cout << max(even, all) << "\n";
      }
    }
  }
}