#include <bits/stdc++.h>
using namespace std;

const int A = 1e6 + 1;

int sieve[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < A; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  int n;
  cin >> n;

  int ans = n;
  for (int i = 0; i < sieve[n]; ++i) {
    if (sieve[n - i] != n - i) {
      ans = min(ans, n - i - sieve[n - i] + 1);
    }
  }

  cout << ans << "\n";
}