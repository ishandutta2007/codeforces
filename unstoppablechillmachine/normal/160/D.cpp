//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
//#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

struct edge {
  int F, S, id;
  edge() {};
  edge(int u, int v, int _id) : F(u), S(v), id(_id) {};
};

const int MX = 1e6 + 10;
vector<edge> h[MX];

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    p.resize(n + 10);
    sz.resize(n + 10, 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
  }
};

bool is_bridge[MX];
int used[MX], up[MX], tin[MX], timer, tt;
vector<pair<int, int>> g[MX];

void dfs(int v, int par = 0) {
  tin[v] = ++timer;
  up[v] = tin[v];
  used[v] = tt;
  for (auto u : g[v]) {
    if (u.F == par) {
      continue;
    }
    if (used[u.F] < tt) {
      dfs(u.F, v);
      up[v] = min(up[v], up[u.F]);
      if (up[u.F] > tin[v]) {
        is_bridge[u.S] = true;
      }
    }
    else {
      up[v] = min(up[v], tin[u.F]);
    }
  }
}

void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    h[c].emplace_back(u, v, i);
  }
  DSU A(n);
  vector<int> ans(m);
  map<pair<int, int>, int> cnt;
  vector<int> vert;
  set<pair<int, int>> was;
  for (int i = 1; i <= 1e6; i++) {
    for (auto it : h[i]) {
      int x = A.find(it.F), y = A.find(it.S);
      if (x > y) {
        swap(x, y);
      }
      if (x == y) {
        ans[it.id] = -1;
      }
      else {
        cnt[{x, y}]++;
      }
    }
    for (auto it : h[i]) {
      if (ans[it.id] == -1) {
        continue;
      }
      int x = A.find(it.F), y = A.find(it.S);
      if (x > y) {
        swap(x, y);
      }
      if (cnt[{x, y}] > 1) {
        ans[it.id] = 1;
        if (was.find({x, y}) == was.end()) {
          was.insert({x, y});
          g[x].pb({y, it.id});
          g[y].pb({x, it.id});
          vert.pb(x);
          vert.pb(y);  
        }
      }
      else {
        g[x].pb({y, it.id});
        g[y].pb({x, it.id});
        vert.pb(x);
        vert.pb(y);
      }
    }
    was = {};
    tt++;
    for (auto it : vert) {
      if (used[it] < tt) {
        dfs(it);
      }
    }
    for (auto it : vert) {
      g[it] = {};
    }
    vert = {};
    cnt = {};
    for (auto it : h[i]) {
      A.merge(it.F, it.S);
    }
  }
  int cur = 0;
  for (auto it : ans) {
    if (it == -1) {
      cout << "none\n";
    }
    else if (it == 1) {
      cout << "at least one\n";
    }
    else {
      if (is_bridge[cur]) {
        cout << "any\n";
      }
      else {
        cout << "at least one\n";
      }
    }
    cur++;
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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