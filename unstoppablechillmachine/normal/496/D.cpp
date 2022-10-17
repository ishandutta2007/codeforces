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
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }
  vector<int> arr1, arr2;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      arr1.pb(i);
    }
    else {
      arr2.pb(i);
    }
  }
  vector<int> l1(n, -1), l2(n, -1);
  for (int i = 1; i < n; i++) {
    l1[i] = l1[i - 1];
    l2[i] = l2[i - 1];
    if (a[i - 1] == 1) {
      l1[i]++;
    }
    else {
      l2[i]++;
    }
  }
  int s1 = 0, s2 = 0;
  vector<pii> ans;
  for (int i = 0; i < n; i++) {
    int cnt, st1 = 0, st2 = 0;
    if (a[i] == 1) {
      s1++;
      st1 = 1;
      if (s1 <= s2) {
        continue;
      }
      cnt = s1;
    }
    else {
      s2++;
      if (s2 <= s1) {
        continue;
      }
      cnt = s2;
      st2 = 1;
    }
    int ind1 = s1, ind2 = s2, cur = i + 1;
    bool ok = true;
    while (cur < n) {
      int pos1 = INF, pos2 = INF;
      if (ind1 + cnt - 1 < SZ(arr1)) {
        pos1 = arr1[ind1 + cnt - 1];
      }
      if (ind2 + cnt - 1 < SZ(arr2)) {
        pos2 = arr2[ind2 + cnt - 1];
      }
      if (min(pos1, pos2) == INF) {
        ok = false;
        break;
      }
      if (pos1 < pos2) {
        st1++;
      }
      else {
        st2++;
      }
      cur = min(pos1, pos2) + 1;
      if (cur < n) {
        ind1 = l1[cur] + 1;
        ind2 = l2[cur] + 1;
      }
    }
    if (a.back() == 1) {
      if (st1 <= st2) {
        ok = false;
      }
    }
    else {
      if (st2 <= st1) {
        ok = false;
      }
    }
    if (ok) {
      if (a.back() == 1) ans.pb({st1, cnt});
      else ans.pb({st2, cnt});
    }
  }
  sort(all(ans));
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