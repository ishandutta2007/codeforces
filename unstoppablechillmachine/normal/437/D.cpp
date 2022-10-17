//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    sz.resize(n + 10, 1);
    p.resize(n + 10);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  int merge(int a, int b) {
    a = find(a), b = find(b);
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    int res = sz[a] * sz[b];
    sz[a] += sz[b];
    sz[b] = 0;
    return res;
  }
};

void source() {
  int n, m;
  cin >> n >> m;
  vector<pii> kek;
  vector<int> arr(n + 1);
  for (int  i = 1; i <= n; i++) {
    cin >> arr[i];
    kek.pb({arr[i], i});
  }
  sort(rall(kek));
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<bool> can(n + 1);
  DSU A(n);
  int ans = 0;
  for (auto v : kek) {
    for (auto u : g[v.S]) {
      if (can[u] && A.find(u) != A.find(v.S)) {
        ans += A.merge(u, v.S) * v.F;
      }
    }
    can[v.S] = true;
  }
  cout << fixed << setprecision(10) << (ld)ans * 2.0 / ((ld)n * (ld)(n - 1));
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