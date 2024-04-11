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
int MOD;

void source() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  unordered_map<int, int> cnt;
  for (auto &it : a) {
    cin >> it;
    cnt[it]++;
  }
  for (auto &it : b) {
    cin >> it;
    cnt[it]++;
  }
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      p++;
    }
  }
  cin >> MOD;
  vector<pair<int, int> > fact(2 * n + 1);
  fact[0] = {1, 0};
  for (int i = 1; i <= 2 * n; i++) {
    int x = i, c = 0;
    while (x % 2 == 0) {
      x /= 2;
      c++;
    }
    fact[i].F = (fact[i - 1].F * x) % MOD;
    fact[i].S = (fact[i - 1].S + c);
  }
  int ans = 1, all = -p;
  for (auto it : cnt) {
    ans = (ans * fact[it.S].F) % MOD;
    all += fact[it.S].S;
  }
  for (int i = 0; i < all; i++) {
    ans = (ans * 2) % MOD;
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