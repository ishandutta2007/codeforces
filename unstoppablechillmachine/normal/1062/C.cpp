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

const int MOD = 1e9 + 7;

void source() {
  int n, q;
  cin >> n >> q;
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '1') {
      pref[i] = pref[i - 1] + 1;
    }
    else {
      pref[i] = pref[i - 1];
    }
  }
  vector<int> calc(pref[n] + 1), p(n + 1);
  calc[0] = 0;
  p[0] = 1;
  for (int i = 1; i <= pref[n]; i++) {
    calc[i] = (calc[i - 1] * 2 + 1) % MOD;
    p[i] = (p[i - 1] * 2) % MOD;
  }
  for (int i = pref[n] + 1; i <= n; i++) {
    p[i] = (p[i - 1] * 2) % MOD;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int cnt1 = pref[r] - pref[l - 1], cnt2 = (r - l + 1) - cnt1;
    cout << (calc[cnt1] * p[cnt2]) % MOD << '\n';
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