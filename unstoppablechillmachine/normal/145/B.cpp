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
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void solve(int start, int cnt0, int cnt1, int cnt01, int cnt10) {
  vector<int> ans;
  ans.pb(start);
  if (start == 0) {
    cnt0--;
  }
  else {
    cnt1--;
  }
  while (cnt01 || cnt10) {
    if (start == 0) {
      if (cnt1 == 0 || cnt01 == 0) {
        return;
      }
      ans.pb(1);
      start = 1;
      cnt1--;
      cnt01--;
    }
    else {
      if (cnt0 == 0 || cnt10 == 0) {
        return;
      }
      ans.pb(0);
      start = 0;
      cnt0--;
      cnt10--;
    }  
  }
  int f = 0;
  for (auto it : ans) {
    f += (it == 1);
  }
  for (auto it : ans) {
    if (it == 0) {
      cout << 4;
      if (cnt0) {
        for (int i = 0; i < cnt0; i++) {
          cout << 4;
        }
        cnt0 = 0;
      }
    }
    else {
      cout << 7;
      f--;
      if (cnt1 && f == 0) {
        for (int i = 0; i < cnt1; i++) {
          cout << 7;
        }
        cnt1 = 0;
      }
    }
  }
  exit(0);
}

void source() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  if (abs(a3 - a4) > 1) {
    cout << -1;
    exit(0);
  }
  solve(0, a1, a2, a3, a4);
  solve(1, a1, a2, a3, a4);
  cout << -1;
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