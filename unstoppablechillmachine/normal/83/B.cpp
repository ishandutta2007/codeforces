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

void source() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1);
  multiset<int> have;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum += arr[i];
    have.insert(arr[i]);
  }
  if (sum < k) {
    cout << -1;
    exit(0);
  }
  int delta = 0;
  while (k > 0) {
    if (have.empty()) {
      exit(0);
    }
    int cur = SZ(have), mn = *have.begin() - delta;
    if (cur * mn <= k) {
      k -= cur * mn;
      delta = *have.begin();
      while (!have.empty() && *have.begin() == delta) {
        have.erase(have.begin());
      }
    }
    else {
      int iter = k / cur;
      k -= iter * cur;
      delta += iter;
      break;
    }
  }
  if (have.empty()) {
    exit(0);
  }
  deque<pii> d;
  for (int i = 1; i <= n; i++) {
    if (arr[i] - delta > 0) {
      d.pb({arr[i] - delta, i});
    }
  }
  for (int i = 0; i < k; i++) {
    pii c = d.front();
    d.pop_front();
    if (c.F > 1) {
      c.F--;
      d.pb(c);
    }
  }
  for (auto it : d) {
    cout << it.S << ' ';
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