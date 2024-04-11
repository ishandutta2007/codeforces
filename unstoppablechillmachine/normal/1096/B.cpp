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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int MOD = 998244353;

void source() {
  int n;
  cin >> n;
  vector<char> c(n + 1);
  vector<bool> pref(n + 2), suf(n + 2);
  pref[0] = true;
  suf[n + 1] = true;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    pref[i] = pref[i - 1] & (c[i] == c[1]);
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] & (c[i] == c[n]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!pref[i - 1]) {
      break;
    }
    int l = 0, r = n - i + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      bool ok = true;
      if (pref[i - 1] && suf[i + mid]) {
        if (i > 1 && i + mid <= n && c[1] != c[n]) {
          ok = false;
        }
      }
      else {
        ok = false;
      }
      if (ok) {
        r = mid;
      }
      else {
        l = mid;
      }
    }
    //cout << i << ' ' << r << '\n';
    ans += (n - i + 1) - r + 1;
  }
  cout << ans % MOD;
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