#include <bits/stdc++.h>
using namespace std;

// cases:
//   a is the square of a prime - p^2, 3 divisors
//   a is a multiple of two primes - pq, 4 divisors
//   a is the cube of a prime - p^3, 4 divisors
//   a is the hypercube of a prime - p^4, 5 divisors

const int P[] = {0, 0, 1500000000, 1300000, 40000};
const int M = 998244353;
const int N = 500;

long long pow(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res *= a;
    }
    a *= a;
    b /= 2;
  }
  return res;
}

long long find(long long a, int b) {
  long long lo = 0, hi = P[b];
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (pow(mid, b) < a) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

long long a[N];
bool found[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<long long, int> factors;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 4; j >= 2 && !found[i]; --j) {
      long long p = find(a[i], j);
      if (pow(p, j) == a[i]) {
        factors[p] += j;
        found[i] = true;
      }
    }
  }

  map<long long, int> mystery;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n && !found[i]; ++j) {
      long long g = __gcd(a[i], a[j]);
      if (g != a[i] && g != 1) {
        found[i] = true;
        ++factors[a[i] / g];
        ++factors[g];
      }
    }
    if (!found[i]) {
      ++mystery[a[i]];
    }
  }

  long long ans = 1;
  for (auto [p, a] : factors) {
    ans = ans * (a + 1) % M;
  }
  for (auto [p, a] : mystery) {
    ans = ans * (a + 1) * (a + 1) % M;
  }

  cout << ans << "\n";
}