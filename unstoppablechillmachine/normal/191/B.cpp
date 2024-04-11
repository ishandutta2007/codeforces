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
  int n, k, have;
  cin >> n >> k >> have;
  int ans = n;
  n--;
  k = min(k, n);
  vector<pii> arr(n);
  int cur = 0;
  for (auto &it : arr) {
    cin >> it.F;
    it.S = ++cur;
  }
  sort(all(arr));
  vector<int> suf(n);
  suf[n - 1] = arr[n - 1].S;
  multiset<int> can;
  can.insert(arr.back().F);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = min(suf[i + 1], arr[i].S);
    can.insert(arr[i].F);
  }
  int sum = 0;
  for (int i = 0; i < k; i++) {
    if (can.upper_bound(have - sum) != can.end()) {
      int ind = lower_bound(all(arr), MP(have - sum + 1, 0ll)) - arr.begin();
      ans = min(ans, suf[ind]);
    }
    auto it = can.upper_bound(have - sum);
    if (it == can.begin()) {
      break;
    }
    it--;
    sum += *it;
    can.erase(it);
    debug(sum);
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