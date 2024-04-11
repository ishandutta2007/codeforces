//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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

const int N = 1010;
bool used[N][N];

void go2(pii from, pii to, vector<pii> &ans) {
  while (from.F != to.F) {
    used[from.F][from.S] = true;
    ans.pb(from);
    if (from.F > to.F) {
      from.F--;
    }
    else {
      from.F++;
    }
  }
  while (from.S != to.S) {
    used[from.F][from.S] = true;
    ans.pb(from);
    if (from.S > to.S) {
      from.S--;
    }
    else {
      from.S++;
    }
  }
  used[to.F][to.S] = true;
}

void go1(pii from, pii to, vector<pii> &ans) {
  while (from.S != to.S) {
    used[from.F][from.S] = true;
    ans.pb(from);
    if (from.S > to.S) {
      from.S--;
    }
    else {
      from.S++;
    }
  }
  while (from.F != to.F) {
    used[from.F][from.S] = true;
    ans.pb(from);
    if (from.F > to.F) {
      from.F--;
    }
    else {
      from.F++;
    }
  }
  used[to.F][to.S] = true;
}

void source() {
  vector<pii> arr(3);
  for (auto &it : arr) {
    cin >> it.F >> it.S;
  }
  sort(all(arr));
  vector<pii> ans;
  if (abs(arr[0].S - arr[1].S) + abs(arr[1].S - arr[2].S) == abs(arr[0].S - arr[2].S)) {
    go1(arr[0], arr[1], ans);
    go1(arr[1], arr[2], ans);
    ans.pb(arr[2]);
  }
  else {
    if (arr[1].S > max(arr[0].S, arr[2].S)) {
      if (arr[0].S <= arr[2].S) {
        go1(arr[0], arr[2], ans);
      }
      else {
        go2(arr[0], arr[2], ans);
      }
      ans.pb(arr[2]);
      while (!used[arr[1].F][arr[1].S]) {
        ans.pb(arr[1]);
        arr[1].S--;
      }
    }
    else {
      if (arr[0].S <= arr[2].S) {
        go2(arr[0], arr[2], ans);
      }
      else {
        go1(arr[0], arr[2], ans);
      }
      ans.pb(arr[2]);
      while (!used[arr[1].F][arr[1].S]) {
        ans.pb(arr[1]);
        arr[1].S++;
      }  
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
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