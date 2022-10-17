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
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 210;
vector<int> g[N];
int calc[N][N];

pair<int, int> dfs(int v, int cannot, int par = 0, int h = 0) {
  pair<int, int> res = {h, v};
  for (auto u : g[v]) {
    if (u != par && u != cannot) {
      res = max(res, dfs(u, cannot, v, h + 1));
    }
  }  
  return res;
}

int get_diam(int root, int cannot) {
  pair<int, int> cur = dfs(root, cannot);
  return dfs(cur.S, cannot).F;
}

void source() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    for (auto u : g[i]) {
      calc[i][u] = get_diam(i, u);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto u : g[i]) {
      ans = max(ans, calc[i][u] * calc[u][i]);
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