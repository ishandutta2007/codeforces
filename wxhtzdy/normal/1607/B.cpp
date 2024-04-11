#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x, n;
    cin >> x >> n;
    for (long long i = n - n % 4 + 1; i <= n; i++) {
      x += i * (x % 2 == 0 ? -1 : 1);
    }
    cout << x << '\n';
  }
  return 0;
}