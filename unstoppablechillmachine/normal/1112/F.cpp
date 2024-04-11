#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 2e5 + 10;
vector<int> g[N];
int a[N], dp[N][2];
bool ans[N];

void dfs(int v, int par = 0) {
  int mx = 0, sum = 0, cnt = 0;
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v);
      mx = max(mx, dp[u][1] - dp[u][0]);
      sum += dp[u][1];
      cnt++;
    }
  }
  if (cnt == 0) {
    dp[v][1] = a[v];
    dp[v][0] = 0;
  }
  else {
    dp[v][1] = sum + a[v] - max(mx, a[v]);
    dp[v][0] = sum - mx;
  }
}

pair<bool, bool> can[N];

void dfs2(int v, int par = 0) {
  int mx = -1, lol = 0, ccc = 1;
  for (auto u : g[v]) {
    if (u != par) {
      lol++;
      if (dp[u][1] - dp[u][0] > mx) {
        mx = dp[u][1] - dp[u][0];
        ccc = 1;
      }
      else if (dp[u][1] - dp[u][0] == mx) {
        ccc++;
      }
    }
  }
  if (lol == 0) {
    ans[v] = can[v].F;
    return;
  }
  if (can[v].F && a[v] <= mx) {
    ans[v] = true;
  }
  for (auto u : g[v]) {
    if (u != par) {
      if ((can[v].F && a[v] >= mx) || (dp[u][1] - dp[u][0] < mx) || (dp[u][1] - dp[u][0] == mx && ccc > 1)) {
        can[u].F = true;
      }
      if ((can[v].S && dp[u][1] - dp[u][0] == mx) || (can[v].F && a[v] <= mx && dp[u][1] - dp[u][0] == mx)) {
        can[u].S = true;
      }
      dfs2(u, v);
    }
  }
}

void source() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  can[1] = {1, 0};
  dfs2(1);
  /*for (int i = 1; i <= n; i++) {
    cout << can[i].F << ' ' << can[i].S << '\n';
  }*/
  cout << dp[1][1] << ' ';
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      res.pb(i);
    }
  }
  cout << SZ(res) << '\n';
  for (auto it : res) {
    cout << it << ' ';
  }
}
signed main() {
#ifdef extraterrestrial_
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}