//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 1e6 + 10;
const int P = 239017;
int p_pow[N], hs[N];
vector<int> g[N];
unordered_map<int, int> h;

void source() {
  p_pow[0] = 1;
  for (int i = 1; i <= 1e6; i++) {
    p_pow[i] = p_pow[i - 1] * P;
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    hs[u] += p_pow[v] * v;
    hs[v] += p_pow[u] * u;
  }
  for (int i = 1; i <= n; i++) {
    h[hs[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto u : g[i]) {
      if (hs[u] - p_pow[i] * i == hs[i] - p_pow[u] * u) {
        ans++;
      }
    }
    ans += h[hs[i]] - 1;
  }
  cout << ans / 2;
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