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
  int n, k;
  cin >> n >> k;
  if (k > n || __builtin_popcount(n) > k) {
    cout << "NO";
    exit(0);
  }
  vector<int> c(30);
  for (int i = 0; i < 30; i++) {
    if (n & pw(i)) {
      c[i]++;
      k--;
    }
  }
  for (int i = 29; i > 0; i--) {
    while (k > 0 && c[i] > 0) {
      c[i]--;
      c[i - 1] += 2;
      k--;
    }
  }
  if (k != 0) {
    cout << "NO";
    exit(0);
  }
  cout << "YES\n";
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < c[i]; j++) {
      cout << (1 << i) << ' ';
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