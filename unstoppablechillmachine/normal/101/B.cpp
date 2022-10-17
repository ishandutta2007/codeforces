//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
//#define int ll
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

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

void source() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> seg;
  set<int> have;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    seg[r].pb(l);
    have.insert(r);
  }
  have.insert(0);
  unordered_map<int, int> dp, pref;
  dp[0] = 1;
  pref[0] = 1;
  int prev = 0;
  for (auto i : have) {
    for (auto it : seg[i]) {
      auto kek = have.lower_bound(i);
      if (kek == have.begin()) {
        continue;
      }
      kek--;
      if (*kek >= it) {
        int cur = pref[*kek];
        auto lol = have.lower_bound(it);
        if (lol != have.begin()) {
          lol--;
          sub(cur, pref[*lol]);
        }
        add(dp[i], cur);
      }
    }
    pref[i] = prev;
    add(pref[i], dp[i]);
    prev = pref[i];
  }
  cout << dp[n];
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