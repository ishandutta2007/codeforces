#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  long long r = min(r1, r2), l = max(l1 - 1, l2 - 1);
  long long ans = max(0LL, r - l);
  if (l <= k && k <= r) {
    ans -= 1;
  }
  cout << ans << '\n';
  return 0;
}