#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long ans = 0;
  priority_queue<tuple<long long, long long, long long>> s;
  auto Calc = [&](long long x, long long y) {
    long long q = x / y, w = x % y;
    return q * q * (y - w) + (q + 1) * (q + 1) * w;
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i] * a[i];
    if (a[i] == 1) {
      continue;
    }
    s.push(make_tuple(Calc(a[i], 1) - Calc(a[i], 2), a[i], 2));
  }
  for (int i = 0; i < k - n; i++) {
    assert(!s.empty());
    auto it = s.top();
    s.pop();
    ans -= get<0>(it);
    if (get<1>(it) == get<2>(it)) continue;
    s.push(make_tuple(Calc(get<1>(it), get<2>(it)) - Calc(get<1>(it), get<2>(it) + 1), get<1>(it), get<2>(it) + 1));
  }
  cout << ans << '\n';
  return 0;
}