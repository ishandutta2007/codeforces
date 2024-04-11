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

const int MX = 2e6 + 10;
pair<int, int> lst[MX], res[MX];

vector<int> factorize(int x) {
  vector<int> res;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      res.pb(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    res.pb(x);
  }
  return res;
}

const int N = 1e5 + 10;
int h[N], a[N];
vector<int> g[N];
vector<pair<int, pair<int, int>>> rb;

void dfs(int v, int par = 0, int curh = 0) {
  vector<int> lol = factorize(a[v]);
  res[v] = {0, 0};
  h[v] = curh;
  int wasSZ = SZ(rb);
  for (auto it : lol) {
    res[v] = max(res[v], lst[it]);
    rb.pb({it, lst[it]});
    lst[it] = {h[v], v};
  }
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v, curh + 1);
    }
  }
  while (SZ(rb) > wasSZ) {
    lst[rb.back().F] = rb.back().S;
    rb.pop_back();
  }
}

void rebuild() {
  for (int i = 1; i <= 2e6; i++) {
    lst[i] = {0, 0};
  }
  dfs(1);
}

void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  rebuild();
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int v;
      cin >> v;
      if (res[v].S == 0) {
        cout << -1 << '\n';
      }
      else {
        cout << res[v].S << '\n';
      }
    }
    else {
      int v, vl;
      cin >> v >> vl;
      a[v] = vl;
      rebuild();
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