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

vector<pii> parse(string s, int n) {
  int l = -INF, r = -INF;
  vector<pii> res;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      if (l == -INF) {
        l = r = i;
      }
      else {
        r = i;
      }
    }
    else {
      if (l != -INF) {
        res.pb({l, r});
        l = r = -INF;
      }
    }
  }
  if (l != -INF) {
    res.pb({l, r});
  }
  return res;
}

void source() {
  int n;
  string s;
  cin >> n >> s;
  vector<pii> seg = parse(s, n);
  int ans = 0;
  for (auto it : seg) {
    ans = max(ans, it.S - it.F + 1 + (SZ(seg) > 1));
  }
  for (int i = 0; i + 1 < SZ(seg); i++) {
    if (seg[i].S + 2 == seg[i + 1].F) {
      ans = max(ans, (seg[i + 1].S - seg[i + 1].F + 1) + (seg[i].S - seg[i].F + 1) + (SZ(seg) > 2));
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