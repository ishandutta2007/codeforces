//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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
  int n, m;
  cin >> n >> m;
  vector<int> sum(n + 1), val(n + 1), min_pref(n + 1), max_pref(n + 1), max_suf(n + 1);
  for (int i = 1; i <= n; i++) {
    int len;
    cin >> len;
    max_pref[i] = val[i] = -INF;
    min_pref[i] = 0;
    vector<int> kek;
    for (int j = 1; j <= len; j++) {
      int x;
      cin >> x;
      kek.pb(x);
      sum[i] += x;
      max_pref[i] = max(max_pref[i], sum[i]);
      val[i] = max(val[i], sum[i] - min_pref[i]);
      min_pref[i] = min(min_pref[i], sum[i]);
    }
    reverse(all(kek));
    max_suf[i] = -INF;
    int s = 0;
    for (auto it : kek) {
      s += it;
      max_suf[i] = max(max_suf[i], s);
    }
    //cout << max_pref[i] << ' ' << max_suf[i] << ' ' << val[i] << '\n'; 
  }
  int ans = -BINF, mx_suf = 0;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    ans = max(ans, val[num]);
    ans = max(ans, max_pref[num] + mx_suf);
    mx_suf = max(max_suf[num], mx_suf + sum[num]);
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