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

const int N = 1010;
int pref[N][N];

int get_sum(int i1, int j1, int i2, int j2) {
  return pref[i2][j2] - pref[i2][j1 - 1] - pref[i1 - 1][j2] + pref[i1 - 1][j1 - 1];
}

void source() {
  int n, m;
  cin >> n >> m;
  set<pair<char, pii>> have;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        pref[i][j] = 1;
      }
      if (c >= 'A' && c <= 'Z') {
        have.insert(MP(c, MP(i, j)));
      }
    }    
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] += pref[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] += pref[i - 1][j];
    }
  }
  int k;
  cin >> k;
  vector<pii> go(k);
  for (int i = 0; i < k; i++) {
    char c;
    int val;
    cin >> c >> val;
    if (c == 'N' || c == 'W') {
      val *= -1;
    }
    if (c == 'N' || c == 'S') {
      go[i] = {1, val};
    }
    else {
      go[i] = {2, val};
    }
  }
  bool okk = false;
  for (auto it : have) {
    pii cur = it.S;
    bool ok = true;
    for (auto it2 : go) {
      if (it2.F == 1) {
        if (cur.F + it2.S >= 1 && cur.F + it2.S <= n) {
          int l = cur.F, r = cur.F + it2.S;
          if (l > r) {
            swap(l, r);
          }
          if (get_sum(l, cur.S, r, cur.S) > 0) {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }
        cur.F += it2.S;
      }
      else {
        if (cur.S + it2.S >= 1 && cur.S + it2.S <= m) {
          int l = cur.S, r = cur.S + it2.S;
          if (l > r) {
            swap(l, r);
          }
          if (get_sum(cur.F, l, cur.F, r) > 0) {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }
        cur.S += it2.S;  
      }
    }
    if (ok) {
      okk = true;
      cout << it.F;
    }
  }
  if (!okk) {
    cout << "no solution";
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