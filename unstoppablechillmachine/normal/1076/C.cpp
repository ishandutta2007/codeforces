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

pair<ld, ld> solve(ld a, ld b, ld c) {
  ld D = b * b - 4 * a * c;
  if (D < 0) {
    return {-BINF, -BINF};
  }
  return {(-b - sqrt(D)) / (a * 2.0), (-b + sqrt(D)) / (a * 2.0)};
}

void source() {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    pair<ld, ld> mem = solve(1, -d, d);
    if (mem.F < 0 || mem.S < 0) {
      cout << "N\n";
    }
    else {
      cout << "Y ";
      cout << fixed << setprecision(10) << mem.F << ' ' << mem.S << '\n'; 
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