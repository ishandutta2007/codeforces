#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b * c) {
      cout << -1 << "\n";
      continue;
    }

    if (d >= c) {
      cout << a << "\n";
      continue;
    }

    // if the enemy doesn't die before one attack cycle, it is impossible to defeat it
    long long lo = 1;
    long long hi = (c + d - 1) / d;

    while (lo < hi) {
      long long attacks = (lo + hi + 1) / 2;
      if ((attacks - 1) * b * d > a) {
        hi = attacks - 1;
      } else {
        lo = attacks;
      }
    }

    cout << lo * a - lo * (lo - 1) / 2 * b * d << "\n";
  }
}