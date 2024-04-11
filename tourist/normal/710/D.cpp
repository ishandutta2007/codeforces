#include <bits/stdc++.h>

using namespace std;

void solve(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  long long xx, yy;
  solve(b, a % b, xx, yy);
  // b * xx + (a - (a / b) * b) * yy == 1
  // a * yy + b * (xx - yy * (a / b)) == 1
  x = yy;
  y = xx - yy * (a / b);
}

long long gcd(long long a, long long b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int main() {
  long long a1, b1, a2, b2, L, R;
  cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
  // a1 * k + b1 == a2 * l + b2
  // a1 * k - a2 * l == b2 - b1
  long long g = gcd(a1, a2);
  if ((b2 - b1) % g != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long k, l;
  solve(a1, a2, k, l);
  k *= (b2 - b1) / g;
  l *= (b1 - b2) / g;
  long long c1 = a1 / g;
  long long c2 = a2 / g;
  long long shift = min(k / c2, l / c1);
  k -= shift * c2;
  l -= shift * c1;
  while (k < 0 || l < 0) {
    k += c2;
    l += c1;
  }
  while (k >= c2 && l >= c1) {
    k -= c2;
    l -= c1;
  }
  long long start = a1 * k + b1;
  assert(start == a2 * l + b2);
  long long step = a1 / g * a2;
  if (start < L) {
    start += (L - start) / step * step;
  }
  while (start < L) {
    start += step;
  }
  long long ans = 0;
  if (start <= R) {
    ans = (R - start) / step + 1;
  }
  cout << ans << endl;
  return 0;
}