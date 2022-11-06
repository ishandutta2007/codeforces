#include <bits/stdc++.h>
#define INF 4557430888798830400ll
using namespace std;

const int maxn = 100 + 5, maxm = 20;

struct Friend {
  int x, k, solve;
  bool operator<(const Friend& f) const {
    return k < f.k;
  }
} f[maxn];

int N, M, b, m, t;
unsigned long long dp[1 << maxm], ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M >> b;
  for (int i = 0; i < N; ++i) {
    cin >> f[i].x >> f[i].k >> m;
    f[i].solve = 0;
    while (m--) cin >> t, f[i].solve += 1 << (t - 1);
  }
  sort(f, f + N);
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0; ans = INF;
  for (int i = 0; i < N; ++i) {
    for (int j = (1 << M) - 1; j >= 0; --j) {
      if (dp[j] < INF) dp[j | f[i].solve] = min(dp[j | f[i].solve], dp[j] + f[i].x);
    }
    ans = min(ans, dp[(1 << M) - 1] + 1LL * f[i].k * b);
  }
  if (ans < INF) cout << ans << '\n';
  else cout << "-1\n";
  return 0;
}