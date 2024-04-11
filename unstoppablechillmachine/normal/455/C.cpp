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

struct DSU {
  vector<int> p, sz, calc;
  DSU(int n) {
    p.resize(n + 1);
    sz.resize(n + 1);
    calc.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = calc[i] = 1;
    }
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
    calc[a] = max(calc[a], max(calc[b], (calc[a] + 2) / 2 + (calc[b] + 2) / 2));
  }
};

const int N = 3e5 + 10;
vector<int> g[N];

pair<int, int> dfs1(int v, int par = 0, int h = 1) {
  pair<int, int> res = {h, v};
  for (auto u : g[v]) {
    if (u != par) {
      res = max(res, dfs1(u, v, h + 1));
    }
  }
  return res;
}

int dfs2(int v, int par = 0, int h = 1) {
  int mx = h;
  for (auto u : g[v]) {
    if (u != par) {
      mx = max(mx, dfs2(u, v, h + 1));
    }
  }
  return mx;
}

void source() {
  int n, m, q;
  cin >> n >> m >> q;
  DSU kek(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    kek.merge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (kek.find(i) == i) {
      pair<int, int> best = dfs1(i);
      kek.calc[i] = dfs2(best.S);
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int v;
      cin >> v;
      cout << kek.calc[kek.find(v)] - 1 << '\n';      
    }
    else {
      int u, v;
      cin >> u >> v;
      kek.merge(u, v);
      debug(kek.calc[kek.find(v)]);
    }
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