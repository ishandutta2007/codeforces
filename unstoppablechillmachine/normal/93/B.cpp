//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
//#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const ld eps = 1e-6;

void source() {
  int n, w, m;
  cin >> n >> w >> m;
  ld need = (ld)n * (ld)w / (ld)m;
  int cur = 1, in = 0;
  ld ost = w;
  vector<vector<pair<int, ld>>> ans(m + 1);
  for (int i = 1; i <= m; i++) {
    //cout << cur << ' ' << ost << ' ' << in << '\n';
    ld can = need;
    //cout << can << ' ' << ost << '\n';
    while (can - ost > -eps) {
      //cout << i << ' ';
      if (ost > eps) ans[i].pb({cur, ost});
      can -= ost;
      ost = w;
      cur++;
      in = 0;
    }
    if (can > eps) {
      ans[i].pb({cur, can});
      ost -= can;
      in++;
      if (in == 2) {
        cout << "NO";
        exit(0);
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    for (auto it : ans[i]) {
      cout << it.F << ' ';
      cout << fixed << setprecision(10) << it.S << ' '; 
    }
    cout << '\n';
  } 
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
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