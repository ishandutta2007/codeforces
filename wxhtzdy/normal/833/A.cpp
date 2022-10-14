#include <bits/stdc++.h>

using namespace std;

long long cubic_root(long long x)
{
    long long l = 0, r = 1e6 + 5;
    while (l != r) {
        long long m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    long long s = (long long) cubic_root(a * b);
    if (s * s * s == a * b && a % s == 0 && b % s == 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}