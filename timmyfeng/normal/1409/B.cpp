#include <bits/stdc++.h>
using namespace std;

int64_t solve(int a, int b, int x, int y, int n) {
  if (a - x <= n) {
    n -= a - x;
    a = x;
  } else {
    a -= n;
    n = 0;
  }

  if (b - y <= n) {
    n -= b - y;
    b = y;
  } else {
    b -= n;
    n = 0;
  }
  return 1LL * a * b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n)) << "\n";
  }
}