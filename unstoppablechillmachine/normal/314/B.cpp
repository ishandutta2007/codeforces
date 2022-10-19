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

void source() {
  int a, b;
  cin >> a >> b;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> used(SZ(s2)), was(1010);
  pii cur = {1, 0};
  int ans = 0;
  while (cur.F <= a) {
    if (used[cur.S]) {
      int delta = cur.F - used[cur.S], add = was[cur.F - 1] - was[used[cur.S] - 1];
      ans = was[cur.F - 1];
      while (cur.F + delta <= a) {
        cur.F += delta;
        ans += add;
      }
      break;
    }
    else {
      used[cur.S] = cur.F;
      was[cur.F] = was[cur.F - 1];
      for (auto it : s1) {
        if (it == s2[cur.S]) {
          cur.S++;
          if (cur.S == SZ(s2)) {
            cur.S = 0;
            was[cur.F]++;
          }
        }
      }
      cur.F++;
    }
  }
  if (cur.F > a) {
    cout << was[a] / b;
  }
  else {
    while (cur.F <= a) {
      for (auto it : s1) {
        if (it == s2[cur.S]) {
          cur.S++;
          if (cur.S == SZ(s2)) {
            ans++;
            cur.S = 0;
          }
        }
      }
      cur.F++;
    }
    cout << ans / b;
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