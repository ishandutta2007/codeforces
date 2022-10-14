#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, k;
    cin >> a >> b >> k;
    cout << (k + 1) / 2 * a - k / 2 * b << '\n';
  }
  return 0;
}