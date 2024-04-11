#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int BINF = 1e18 + 10;

const int N = 5e5 + 10;
struct query {
  int l, r, num;
  query() {};
  query(int _l, int _r, int _num) : l(_l), r(_r), num(_num) {};
};

struct ST {
  vector<int> t, f, arr;
  ST() {};
  void init(int n, vector<int> &_arr) {
    t.resize(4 * n + 10, BINF);
    f.resize(4 * n + 10);
    arr = _arr;
    build(1, 1, n);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      t[v] = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
  void push(int v) {
    f[2 * v] += f[v];
    f[2 * v + 1] += f[v];
    t[2 * v] += f[v];
    t[2 * v + 1] += f[v];
    f[v] = 0;
  }
  void update(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      f[v] += delta;
      t[v] += delta;
      return;
    }
    push(v);
    int mid = (l + r) / 2;
    update(2 * v, l, mid, a, b, delta);
    update(2 * v + 1, mid + 1, r, a, b, delta);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
  int get_min(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
      return BINF;
    }
    if (l >= a && r <= b) {
      return t[v];
    }
    push(v);
    int mid = (l + r) / 2;
    return min(get_min(2 * v, l, mid, a, b), get_min(2 * v + 1, mid + 1, r, a, b));
  }
};
vector<query> q[N];
vector<pair<int, int>> g[N];
int ans[N], cnt = 0, n;
pair<int, int> seg[N];
vector<int> dst;
ST tree;

void precalc(int v, int par = 0, int cd = 0) {
  dst[++cnt] = (SZ(g[v]) == 0 ? cd : BINF);
  seg[v].F = cnt;
  for (auto u : g[v]) {
    if (u.F != par) {
      precalc(u.F, v, cd + u.S);
    }
  }
  seg[v].S = cnt;
}

void dfs(int v, int par = 0) {
  for (auto it : q[v]) {
    ans[it.num] = tree.get_min(1, 1, n, it.l, it.r);
  }
  for (auto u : g[v]) {
    if (u.F != par) {
      tree.update(1, 1, n, 1, n, u.S);
      tree.update(1, 1, n, seg[u.F].F, seg[u.F].S, -2 * u.S);
      dfs(u.F, v);
      tree.update(1, 1, n, 1, n, -u.S);
      tree.update(1, 1, n, seg[u.F].F, seg[u.F].S, 2 * u.S);
    }
  }
}

void source() {
  int m;
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int p, w;
    cin >> p >> w;
    g[p].pb({i, w});
  }
  dst.resize(n + 1);
  precalc(1);
  /*for (int i = 1; i <= n; i++) {
    cout << dst[i] << ' ';
  }
  cout << '\n';*/
  tree.init(n, dst);
  for (int i = 0; i < m; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    q[v].emplace_back(l, r, i);
  }
  dfs(1);
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
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
  return 0;
}