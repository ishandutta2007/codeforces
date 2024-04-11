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
  int n;
  cin >> n;
  int s = 1e6;
  vector<bool> used(s + 10);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    used[x] = true;
    sum += x - 1;
  }
  vector<int> ans;
  for (int i = 1; i <= s; i++) {
    if (used[i]) {
      if (!used[s - i + 1]) {
        ans.pb(s - i + 1);
        sum -= (i - 1);
      }
    }
  }
  for (int i = 1; i <= s; i++) {
    if (!sum) {
      break;
    }
    if (!used[i] && !used[s - i + 1]) {
      sum -= s - 1;
      used[i] = used[s - i + 1] = true;
      ans.pb(i);
      ans.pb(s - i + 1);
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it << ' ';
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