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

void slow_solve(int n, int h, vector<int> &arr, vector<pii> &a2) {
  pii ans = {BINF, BINF};
  for (int i = 0; i < pw(n); i++) {
    vector<int> arr1, arr2;
    for (int j = 0; j < n; j++) {
      if (i & pw(j)) {
        arr1.pb(arr[j]);
      }
      else {
        arr2.pb(arr[j]);
      }
    }
    int mn = INF, mx = -INF;
    if (SZ(arr1) > 1) {
      mn = min(mn, arr1[0] + arr1[1]);
      mx = max(mx, arr1.back() + arr1[SZ(arr1) - 2]);
    }
    if (SZ(arr2) > 1) {
      mn = min(mn, arr2[0] + arr2[1]);
      mx = max(mx, arr2.back() + arr2[SZ(arr2) - 2]);
    }
    if (!arr1.empty() && !arr2.empty()) {
      mn = min(mn, arr1[0] + arr2[0] + h);
      mx = max(mx, arr1.back() + arr2.back() + h);
    }
    ans = min(ans, MP(mx - mn, i));
  }
  cout << ans.F << '\n';
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    if (ans.S & pw(i)) {
      res[a2[i].S] = 1;
    }
    else {
      res[a2[i].S] = 2;
    }
  }
  for (auto it : res) {
    cout << it << ' ';
  }
}

void source() {
  int n, h;
  cin >> n >> h;
  vector<int> arr(n);
  vector<pii> arr2(n);
  for (auto &it : arr) {
    cin >> it;
  }
  for (int i = 0; i < n; i++) {
    arr2[i] = {arr[i], i};
  }
  sort(all(arr));
  sort(all(arr2));
  if (n < 4) {
    slow_solve(n, h, arr, arr2);
    exit(0);
  }
  pii ans = {arr[n - 1] + arr[n - 2] - arr[0] - arr[1], 0};
  int cmx = max(arr[n - 1] + arr[n - 2], arr[n - 1] + arr[0] + h), 
  cmn = min(arr[0] + arr[1] + h, arr[1] + arr[2]);
  ans = min(ans, MP(cmx - cmn, 1ll));
  for (int i = 2; i < n; i++) {
    int mn = min(arr[0] + arr[1] + h, min(arr[0] + arr[i], arr[1] + arr[2])), 
    mx = max(arr[n - 1] + arr[n - 2], arr[i - 1] + arr[n - 1] + h);
    ans = min(ans, MP(mx - mn, i));
  }
  cout << ans.F << '\n';
  if (ans.S == 0) {
    for (int i = 0; i < n; i++) {
      cout << 1 << ' ';
    }
  }
  else if (ans.S == 1) {
    vector<int> res(n, 2);
    res[arr2[0].S] = 1;
    for (auto it : res) {
      cout << it << ' ';
    }
  }
  else {
    vector<int> res(n);
    res[arr2[0].S] = 1;
    for (int i = 1; i < ans.S; i++) {
      res[arr2[i].S] = 2;
    }
    for (int i = ans.S; i < n; i++) {
      res[arr2[i].S] = 1;
    }
    for (auto it : res) {
      cout << it << ' ';
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