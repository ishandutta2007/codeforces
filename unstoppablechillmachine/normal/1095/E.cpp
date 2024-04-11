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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '(') {
      arr[i] = 1;
    }
    else {
      arr[i] = -1;
    }
  }
  vector<int> pref(n + 2), suf(n + 2), mn(n + 2);
  suf[n + 1] = INF;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }
  mn[1] = pref[1];
  for (int i = 2; i <= n; i++) {
    mn[i] = min(mn[i - 1], pref[i]);
  }
  suf[n] = pref[n];
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = min(suf[i + 1], pref[i]);
  }
  int ans = 0, sum = pref[n];
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      if (sum == 2 && mn[i - 1] >= 0 && pref[i - 1] >= 1 && suf[i + 1] >= 2) {
        ans++;
      }
    }
    else {
      if (sum == -2 && mn[i - 1] >= 0 && suf[i + 1] >= -2) {
        ans++;
      }
    }
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