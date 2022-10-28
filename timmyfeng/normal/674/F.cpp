#include <bits/stdc++.h>
using namespace std;

const int P = 130 + 1;

unsigned terms[P], choose[P];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, q;
  cin >> n >> p >> q;

  fill(choose, choose + min(n - 1, p) + 1, 1);
  for (int i = 0; i < min(n - 1, p); ++i) {
    terms[i] = n - i;
    unsigned div = i + 1;
    for (int j = 0; j <= i; ++j) {
      unsigned gcd = __gcd(div, terms[j]);
      terms[j] /= gcd;
      div /= gcd;
      choose[i + 1] *= terms[j];
    }
  }

  unsigned ans = 0;
  for (int i = 1; i <= q; ++i) {
    unsigned sum = 0, pow = 1;
    for (int j = 0; j <= min(n - 1, p); ++j) {
      sum += choose[j] * pow;
      pow *= i;
    }
    ans ^= i * sum;
  }

  cout << ans << "\n";
}