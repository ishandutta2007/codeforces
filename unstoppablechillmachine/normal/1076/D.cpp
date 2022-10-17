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
#define int ll
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

struct edge {
  int F, S, num;
  edge() {};
  edge(int _F, int _S, int _num) : F(_F), S(_S), num(_num) {};
};

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<edge> > g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    g[u].emplace_back(v, cost, i + 1);
    g[v].emplace_back(u, cost, i + 1);
  }
  vector<int> dist(n + 1, BINF);
  dist[1] = 0;
  set<pair<int, int> > st;
  for (int i = 1; i <= n; i++) {
    st.insert({dist[i], i});
  }
  vector<pii> from(n + 1);
  while (!st.empty()) {
    int v = st.begin()->S;
    st.erase(st.begin());
    for (auto u : g[v]) {
      if (dist[v] + u.S < dist[u.F]) {
        st.erase({dist[u.F], u.F});
        dist[u.F] = dist[v] + u.S;
        st.insert({dist[u.F], u.F});
        from[u.F] = {v, u.num};
      }
    }
  }
  vector<vector<pii> > kek(n + 1);
  for (int i = 2; i <= n; i++) {
    kek[from[i].F].pb({i, from[i].S});
  }
  queue<pii> q;
  q.push({1, 0});
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    while (!q.empty() && q.front().S == SZ(kek[q.front().F])) {
      q.pop();
    }
    if (q.empty()) {
      break;
    }
    pii lol = q.front();
    ans.pb(kek[lol.F][lol.S].S);
    q.push({kek[lol.F][lol.S].F, 0});
     q.front().S++;
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it << ' ';
  }
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