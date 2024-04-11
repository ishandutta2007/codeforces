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

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> arr(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  vector<vector<pii>> have(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] != '*') {
        continue;
      }
      for (int rad = 1;; rad++) {
        if (i + rad >= n || i - rad < 0 || j + rad >= m || j - rad < 0) {
          break;
        }
        if (arr[i][j + rad] == '*' && arr[i][j - rad] == '*' && arr[i + rad][j] == '*' && arr[i - rad][j] == '*') {
          have[rad].pb({i, j});
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (SZ(have[i]) >= k) {
      pii cur = have[i][k - 1];
      vector<pii> lol = {{0, 0}, {-i, 0}, {i, 0}, {0, -i}, {0, i}};
      for (auto delta : lol) {
        cout << cur.F + delta.F + 1 << ' ' << cur.S + delta.S + 1 << '\n';
      }
      exit(0);
    }
    else {
      k -= SZ(have[i]);
    }
  }
  cout << -1;
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