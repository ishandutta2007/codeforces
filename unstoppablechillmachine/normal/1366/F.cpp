#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

int inter(pair<int, int> l1, pair<int, int> l2) {
  return (l2.S - l1.S) / (l1.F - l2.F);
}

const int MOD = 1e9 + 7;

inline void add(int &a, int b) {
  a = (a + b) % MOD;
}

inline int sum(int a, int b) {
  return (a + b) % MOD;
}

int mult(int a, int b) {
  a %= MOD;
  b %= MOD;
  return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return mult(b_pow(a, b - 1), a);
  }
  return b_pow(mult(a, a), b >> 1);
}

const int N = 2010;
int dp[N][N];
vector<pair<int, int>> g[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  int mx = 0;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    mx = max(mx, c);
    g[u].pb({v, c});
    g[v].pb({u, c});
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1e18;
    }
  }
  dp[0][1] = 0;
  for (int i = 0; i + 1 < n; i++) {
    for (int v = 1; v <= n; v++) {
      for (auto u : g[v]) {
        dp[i + 1][u.F] = max(dp[i + 1][u.F], dp[i][v] + u.S);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    int mx = 0;
    for (int v = 1; v <= n; v++) {
      mx = max(mx, dp[i][v]);
    }
    add(ans, mx);
  }
  vector<pair<int, int>> lines;
  map<int, int> best;
  for (int v = 1; v <= n; v++) {
    int k = 0;
    for (auto u : g[v]) {
      k = max(k, u.S);
    }
    best[k] = max(best[k], dp[n - 1][v]);
  }
  for (auto it : best) {
    lines.pb({it.F, it.S});
  }
  sort(all(lines));
  vector<int> to(SZ(lines));
  for (int i = 0; i < SZ(lines); i++) {
    to[i] = q;
    for (int j = i + 1; j < SZ(lines); j++) {
      int x = inter(lines[i], lines[j]);
      while (lines[j].F * (x - 1) + lines[j].S >= lines[i].F * (x - 1) + lines[i].S) {
        x--;
      }
      while (lines[j].F * x + lines[j].S < lines[i].F * x + lines[i].S) {
        x++;
      }
      x--;
      to[i] = min(to[i], n - 1 + x);
    }
  }
  int cur = n;
  int inv2 = b_pow(2, MOD - 2);
  for (int i = 0; i < SZ(lines); i++) {
    if (to[i] < cur) {
      continue;
    }
    int a0 = lines[i].F * (cur - (n - 1)) + lines[i].S, an = lines[i].F * (to[i] - (n - 1)) + lines[i].S;
    int vl = mult(inv2, sum(a0, an));
    add(ans, mult(vl, to[i] - cur + 1));
    cur = to[i] + 1;
  }
  cout << ans << '\n';
}