//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
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

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    p.resize(n + 1);
    sz.resize(n + 1, 1);
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

const int N = 1e5 + 10;
const int B = 400;
vector<int> g[N], cur_comp;
int used[N], timer;

void dfs(int v) {
  used[v] = timer;
  cur_comp.pb(v);
  for (auto u : g[v]) {
    if (used[u] < timer) {
      dfs(u);
    }
  }
}

int cnt[N];
vector<pair<int, int>> have[N];
set<int> xx[N];
map<int, int> ans[N];

void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, color;
    cin >> u >> v >> color;
    cnt[color]++;
    have[color].pb({u, v});
    xx[color].insert(u);
    xx[color].insert(v);
  }
  vector<DSU> kek;
  for (int i = 1; i <= m; i++) {
    if (cnt[i] > B) {
      kek.pb(DSU(n));
      for (auto it : have[i]) {
        kek.back().merge(it.F, it.S);
      }
    }
    else {
      for (auto it : xx[i]) {
        g[it] = {};
      }
      for (auto it : have[i]) {
        g[it.F].pb(it.S);
        g[it.S].pb(it.F);
      }
      timer++;
      for (auto it : xx[i]) {
        if (used[it] < timer) {
          cur_comp = {};
          dfs(it);
          for (auto v : cur_comp) {
            for (auto u : cur_comp) {
              if (u < v) {
                ans[u][v]++;
              }
            }
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    int res = ans[u][v];
    for (int i = 0; i < SZ(kek); i++) {
      if (kek[i].find(u) == kek[i].find(v)) {
        res++;
      }
    }
    cout << res << '\n';
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
  //assert(freopen("input.txt", "r", stdin));
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