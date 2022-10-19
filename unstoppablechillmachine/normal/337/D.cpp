//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 1e5 + 10;
vector<int> g[N];
bool f[N];
int dp[N], ans, d;

void dfs(int v, int par = 0) {
  dp[v] = f[v] ? 0 : -INF;
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v);
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }
}

void go(int v, int par = 0, int curmax = -INF) {
  if (max(dp[v], curmax) <= d) {
    ans++;
  }
  vector<int> arr;
  for (auto u : g[v]) {
    if (u != par) {
      arr.pb(u);
    }
  }
  if (arr.empty()) {
    return;
  }
  vector<int> pref(SZ(arr)), suf(SZ(arr));
  pref[0] = dp[arr[0]];
  suf.back() = dp[arr.back()];
  for (int i = 1; i < SZ(arr); i++) {
    pref[i] = max(pref[i - 1], dp[arr[i]]);
  }
  for (int i = SZ(arr) - 2; i >= 0; i--) {
    suf[i] = max(suf[i + 1], dp[arr[i]]);
  }
  for (int i = 0; i < SZ(arr); i++) {
    int mx = -INF;
    if (i) {
      mx = max(mx, pref[i - 1] + 1);
    }
    if (i + 1 < SZ(arr)) {
      mx = max(mx, suf[i + 1] + 1);
    }
    if (f[v]) {
      mx = max(mx, 0ll);
    }
    go(arr[i], v, max(mx, curmax) + 1);
  }
}

void source() {
  int n, m;
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    f[x] = true;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  go(1);
  cout << ans;
}
 
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}