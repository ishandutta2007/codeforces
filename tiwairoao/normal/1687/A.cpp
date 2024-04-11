#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

ll a[N + 5], k; int n;
ll bi[N + 5], bj[N + 5];

int que[N + 5], s, t;
void solve() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
  for (int i = 0; i < n; i++) bi[i] = -2 * a[i] - (2 * k + i - 1) * i;
  for (int j = 1; j <= n; j++) bj[j] = 2 * a[j] + (2 * k - j - 1) * j;

  ll ans = 0; que[s = t = 1] = 0;
  for (int j = 1; j <= n; j++) {
    while (s <= t && k < j - que[s]) s++;
    ans = std::max(ans, bj[j] + bi[que[s]] + 2ll * que[s] * j);
    // for (int i = std::max(j - k, 0ll); i < j; i++) ans = std::max(ans, bi[i] + bj[j] + 2ll * i * j);
    while (s <= t && bi[que[t]] + 2ll * que[t] * (j + 1) <= bi[j] + 2ll * j * (j + 1)) t--;
    que[++t] = j;
  }
  printf("%lld\n", ans / 2);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
}