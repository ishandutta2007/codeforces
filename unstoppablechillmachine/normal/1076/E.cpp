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

const int N = 3e5 + 10;
int h[N], ans[N];
vector<pii> nw[N];
vector<int> g[N];

struct segment_tree {
  vector<int> t, f;
  void push(int v, int l, int r) {
    if (f[v]) {
      int mid = (l + r) / 2;
      f[2 * v] += f[v];
      f[2 * v + 1] += f[v];
      t[2 * v] += (mid - l + 1) * f[v];
      t[2 * v + 1] += (r - mid) * f[v];
      f[v] = 0;
    }
  }
  void update(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      t[v] += (r - l + 1) * delta;
      f[v] += delta;
      return;
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    update(2 * v , l, mid, a, b, delta);
    update(2 * v + 1, mid + 1, r, a, b, delta);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
  int get(int v, int l, int r, int need) {
    if (l == r) {
      return t[v];
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    if (need <= mid) {
      return get(2 * v, l, mid, need);
    }
    return get(2 * v + 1, mid + 1, r, need);
  }
};

segment_tree tree;

void dfs(int v, int par = 0, int ch = 1) {
  h[v] = ch;
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v, ch + 1);
    }
  }
}

int n;

void dfs2(int v, int par = 0) {
  for (auto it : nw[v]) {
    tree.update(1, 1, n, h[v], h[v] + it.F, it.S);
  }
  ans[v] = tree.get(1, 1, n, h[v]);
  for (auto u : g[v]) {
    if (u != par) {
      dfs2(u, v);
    }
  }
  for (auto it : nw[v]) {
    tree.update(1, 1, n, h[v], h[v] + it.F, -it.S);
  }
}

void source() {
  cin >> n;
  tree.t.resize(4 * n + 10);
  tree.f.resize(4 * n + 10);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, dep, add;
    cin >> v >> dep >> add;
    nw[v].pb({dep, add});
  }
  dfs2(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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