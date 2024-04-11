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

const int N = 1010;
vector<vector<int> > g1;
int tin[N], tout[N], h[N], tt;

void calc_dfs(int v, int par = 0, int hh = 0) {
  tin[v] = tt++;
  h[v] = hh;
  for (auto u : g1[v]) {
    if (u != par) {
      calc_dfs(u, v, hh + 1);
    }
  }
  tout[v] = tt++;
}

bool ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int ask1(int v) {
  cout << "A " << v << endl;
  int u;
  cin >> u;
  return u;
}

int ask2(int v) {
  cout << "B " << v << endl;
  int u;
  cin >> u;
  return u;
}

void print(int v) {
  cout << "C " << v << endl;
}

int used1[N], used2[N], timer;

void source() {
  int t;
  cin >> t;
  while (t--) {
    timer++;
    int n;
    cin >> n;
    g1.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      g1[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g1[u].pb(v);
      g1[v].pb(u);
    }
    int cnt1;
    cin >> cnt1;
    vector<int> arr1(cnt1);
    for (auto &it : arr1) {
      cin >> it;
      used1[it] = timer;
    }
    int cnt2;
    cin >> cnt2;
    vector<int> arr2(cnt2);
    for (auto &it : arr2) {
      cin >> it;
      used2[it] = timer;
    }
    calc_dfs(1);
    vector<pair<int, int> > kek;
    for (int i = 0; i < cnt1; i++) {
      kek.pb({h[arr1[i]], arr1[i]});
    }
    sort(all(kek));
    int u = ask1(kek[0].S);
    if (used2[u] == timer) {
      print(kek[0].S);
      continue;
    }
    int u2 = ask2(arr2[0]);
    if (used1[u2] == timer) {
      print(u2);
      continue;
    }
    if (ancestor(kek[0].S, u2)) {
      int x = kek[0].S;
      for (int i = cnt1 - 1; i >= 0; i--) {
        if (ancestor(kek[i].S, u2)) {
          x = kek[i].S;
          break;
        }
      }
      int uu = ask1(x);
      if (used2[uu] == timer) {
        print(x);
      }
      else {
        cout << "C -1" << endl;
      }
    } 
    else {
      cout << "C -1" << endl;
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