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

struct Deque {
  deque<pll> have;
  void add(pll cur) {
    while (!have.empty() && have.front().F <= cur.F) {
      have.pop_front();
    }
    have.push_front(cur);
  }
  int get(int can) {
    while (!have.empty() && have.back().S < can) {
      have.pop_back();
    }
    assert(!have.empty());
    return have.back().F;
  }
};

void source() {
  int n, k, x;
  cin >> n >> x >> k;
  vector<int> a(n + 1);
  vector<vector<int> > dp(n + 1, vector<int>(k + 1, -1e13));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= x) {
      dp[i][1] = a[i];
    }
  }
  for (int j = 2; j <= k; j++) {
    Deque kek;
    for (int i = 1; i < j; i++) {
      kek.add({dp[i][j - 1], i});
    }
    for (int i = j; i <= n; i++) {
      dp[i][j] = kek.get(i - x) + a[i];
      kek.add({dp[i][j - 1], i});
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if (n - i + 1 <= x) {
      ans = max(ans, dp[i][k]);
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