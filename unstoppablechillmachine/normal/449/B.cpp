//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
//#define int ll
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

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int> > > g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].pb({v, c});
    g[v].pb({u, c});
  }
  vector<ll> dist(n + 1, BINF);
  dist[1] = 0;
  set<int> have;
  for (int i = 0; i < k; i++) {
    int num, d;
    cin >> num >> d;
    dist[num] = min(dist[num], (ll)d);
    have.insert(num);
  }
  vector<bool> can(n + 1, false);
  can[1] = true;
  set<pair<ll, int> > st;
  for (int i = 1; i <= n; i++) {
    st.insert({dist[i], i});
  }
  while (!st.empty()) {
    int v = st.begin()->S;
    if (!can[v]) {
      k--;
    }
    st.erase(st.begin());
    for (auto u : g[v]) {
      if (dist[v] + u.S <= dist[u.F]) {
        st.erase({dist[u.F], u.F});
        dist[u.F] = dist[v] + u.S;
        st.insert({dist[u.F], u.F});
        can[u.F] = true;
      }
    }
  }
  cout << k;
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