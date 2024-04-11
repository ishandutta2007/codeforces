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

const int N = 1e5 + 10;
vector<int> g[N];
int c[N];
pii calc[N];

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int get(pii a, pii b) {
  if (a.F > b.F) {
    swap(a, b);
  }
  int k = a.F / a.S;
  int need = b.S / __gcd(a.S, b.S);
  k -= k % need;
  return a.S * k;
}

int sum;

void dfs(int v, int par = 0) {
  int cnt = 0, l, cur;
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v);
      if (cnt == 0) {
        cur = calc[u].F;
        l = calc[u].S;
      }
      else {
        cur = get(MP(cur, l), calc[u]);
        l = lcm(l, calc[u].S);
      }
      cnt++;
    }
  }
  if (cnt == 0) {
    calc[v] = {c[v], 1};
  }
  else {
    calc[v].F = cur * cnt;
    calc[v].S = l * cnt;
  }
  if (calc[v].F == 0) {
    cout << sum;
    exit(0);
  }
}

void source() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }  
  dfs(1);
  cout << sum - calc[1].F;
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