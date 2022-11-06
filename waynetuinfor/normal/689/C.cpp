#include <bits/stdc++.h>
using namespace std;

long long m;

long long check(long long);

int main() {
  cin >> m;
  long long d = 1LL, ans = 0;
  while (d <= 10000000000000000LL) d <<= 1;
  while (d >>= 1) if (ans + d <= 10000000000000000LL) if (check(ans + d) < m) ans += d;
  ++ans;
  if (check(ans) != m) cout << "-1\n";
  else cout << ans << '\n';
}

long long check(long long x) {
  // cout << "x: " << x << '\n';
  long long ret = 0, osas;
  for (long long i = 1; ; ++i) {
    if (i * i * i > x) { osas = i - 1; break; }
  }
  // cout << "osas: " << osas << '\n';
  for (long long k = 2; k <= osas; ++k) ret += (x / (k * k * k));
  return ret;
}