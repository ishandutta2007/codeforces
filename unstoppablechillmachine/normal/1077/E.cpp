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
//#define int ll
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
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<int> f(2e5 + 10);
  for (auto it : cnt) {
    f[it.S]++;
  }
  vector<int> have;
  for (int i = 1; i <= 2e5; i++) {
    for (int j = 0; j < f[i]; j++) {
      have.pb(i);
    }
  }
  vector<int> pos(2e6, INF);
  int cur = 1;
  for (int i = 0; i < SZ(have); i++) {
    while (have[i] >= cur) {
      pos[cur] = i;
      cur++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= have.back(); i++) {
    int sum = 0, cur = i, cpos = pos[cur];
    while (cpos < SZ(have)) {
      sum += cur;
      cur *= 2;
      cpos = max(cpos + 1, pos[cur]);
    }
    ans = max(ans, sum);
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