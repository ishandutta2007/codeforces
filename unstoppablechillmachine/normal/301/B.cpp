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

int dist(pii a, pii b) {
  return abs(a.F - b.F) + abs(a.S - b.S);
}

void source() {
  int n, c;
  cin >> n >> c;
  vector<int> add(n);
  for (int i = 1; i < n - 1; i++) {
    cin >> add[i];
  }
  vector<pii> arr(n);
  for (auto &it : arr) {
    cin >> it.F >> it.S;
  }
  int l = 0, r = INF;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    add[0] = mid;
    vector<vector<pii>> g(n);
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        if (i != j) g[i].pb({j, c * dist(arr[i], arr[j]) - add[i]});
      }
    }
    vector<int> d(n, INF);
    d[0] = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[j] > 0) {
          continue;
        }
        for (auto u : g[j]) {
          d[u.F] = min(d[u.F], d[j] + u.S);
        }
      }
    }
    if (d.back() <= 0) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  cout << r;
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