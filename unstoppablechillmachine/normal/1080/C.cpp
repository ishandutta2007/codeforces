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

pii get(int x, int y, int x2, int y2) {
  int delta_x = x2 - x + 1, delta_y = y2 - y + 1;
  pii res;
  res.S = delta_x * delta_y / 2;
  res.F = delta_x * delta_y - res.S;
  if (x % 2 != y % 2) {
    swap(res.F, res.S);
  }
  return res;
}

pii operator-(pii a, pii b) {
  return {a.F - b.F, a.S - b.S};
}

void source() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x, y, x2, y2, x3, y3, x4, y4;
    cin >> x >> y >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int black = n * m / 2, white = n * m - black;
    pii cur = {white, black};
    int xx = max(x, x3), xx2 = min(x2, x4), yy = max(y, y3), yy2 = min(y2, y4);
    if (xx <= xx2 && yy <= yy2) {
      pii cnt = get(x, y, x2, y2) - get(xx, yy, xx2, yy2);
      cur = cur - cnt;
      cur.F += (x2 - x + 1) * (y2 - y + 1) - (xx2 - xx + 1) * (yy2 - yy + 1);
      cnt = get(x3, y3, x4, y4);
      cur = cur - cnt; 
      cur.S += (x4 - x3 + 1) * (y4 - y3 + 1);
    }
    else {
      pii cnt = get(x, y, x2, y2);
      cur = cur - cnt;
      cur.F += (x2 - x + 1) * (y2 - y + 1);
      cnt = get(x3, y3, x4, y4);
      cur = cur - cnt;
      cur.S += (x4 - x3 + 1) * (y4 - y3 + 1); 
    }
    cout << cur.F << ' ' << cur.S << '\n';
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