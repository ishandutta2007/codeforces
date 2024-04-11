#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  int ans = (n - 1) * a;
  ans = min(ans, (n - 1) * b);
  ans = min(ans, min(a, b) + (n - 2) * c);
  cout << ans << '\n';
  return 0;
}