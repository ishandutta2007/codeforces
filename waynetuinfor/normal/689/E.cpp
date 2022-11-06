#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5, MOD = 1000000007;
struct Event { long long x, tp; };
vector<Event> ev;
int n, k;
long long dp[maxn], f[maxn], inv_f[maxn];

long long __pow(long long);
long long C(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  f[0] = 1LL;
  for (int i = 1; i <= n; ++i) f[i] = (f[i - 1] * (long long)i) % MOD;
  for (int i = 0; i <= n; ++i) inv_f[i] = __pow(f[i]);
  for (int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    ++r;
    ev.push_back((Event){ l, 1 });
    ev.push_back((Event){ r, -1 });
  }
  sort(ev.begin(), ev.end(), [](const Event& a, const Event& b) {
    return a.x == b.x ? a.tp < b.tp : a.x < b.x;
  });
  long long p = -1000000001LL;
  int cur = 0;
  for (Event e : ev) {
    dp[cur] += e.x - p, dp[cur] %= MOD;
    cur += e.tp;
    p = e.x;
  }
  long long ans = 0;
  for (int i = k; i <= n; ++i) {
    ans += (C(i, k) * dp[i]) % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}

long long __pow(long long a) {
  long long ret = 1, n = MOD - 2;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

long long C(int n, int m) {
  return (f[n] * inv_f[m]) % MOD * inv_f[n - m] % MOD;
}