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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 1e5 + 10;
int mn[N], s[N];
vector<int> g[N];

void calc(int v) {
  mn[v] = (s[v] == -1 ? INF : s[v]);
  for (auto u : g[v]) {
    calc(u);
    mn[v] = min(mn[v], mn[u]);
  }
}

int ans = 0;

void dfs(int v, int on_path = 0) {
  //cout << v << ' ' << on_path << ' ' << mn[v] << '\n';
  if (s[v] >= 0) {
    if (on_path > s[v]) {
      cout << -1;
      exit(0);
    }
    ans += s[v] - on_path;
    for (auto u : g[v]) {
      dfs(u, s[v]);
    }
  }
  else {
    if (mn[v] == INF) {
      return;
    }
    if (mn[v] < on_path) {
      cout << -1;
      exit(0);
    }
    ans += mn[v] - on_path;
    for (auto u : g[v]) {
      dfs(u, mn[v]);
    }
  }
}

void source() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  calc(1);
  dfs(1);
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