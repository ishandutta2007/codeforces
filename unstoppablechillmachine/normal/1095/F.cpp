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

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  set<pii> unused;
  for (int i = 1; i <= n; i++) {
    unused.insert({c[i], i});
  }
  vector<vector<pii>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    g[u].pb({v, cost});
    g[v].pb({u, cost});
  }
  vector<int> dist(n + 1, BINF);
  dist[1] = 0;
  set<pii> st;
  for (int i = 1; i <= n; i++) {
    st.insert({dist[i], i});
  }
  int curmin = BINF, ans = 0;
  vector<bool> used(n + 1);
  while (!st.empty()) {
    int v;
    if (SZ(st) == n) {
      v = st.begin()->S;
    }
    else {
      if (st.begin()->F < curmin + unused.begin()->F) {
        ans += st.begin()->F;
        v = st.begin()->S;
      }
      else {
        ans += curmin + unused.begin()->F;
        v = unused.begin()->S;
      }
    }
    st.erase({dist[v], v});
    unused.erase({c[v], v});
    curmin = min(curmin, c[v]);
    used[v] = true;
    for (auto u : g[v]) {
      if (u.S < dist[u.F] && !used[u.F]) {
        st.erase({dist[u.F], u.F});
        dist[u.F] = u.S;
        st.insert({dist[u.F], u.F});
      }
    }
  }
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