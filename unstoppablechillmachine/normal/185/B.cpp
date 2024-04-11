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

ld get(ld a, ld b, ld c, ld x, ld y, ld z) {
  ld p1, p2, p3;
  if (x == 0) {
    if (a == 0) {
      p1 = log(1.0);
    }
    else {
      return -1;
    }
  }
  else {
    p1 = a * log(x);
  }
  if (y == 0) {
    if (b == 0) {
      p2 = log(1.0);
    }
    else {
      return -1;
    }
  }
  else {
    p2 = b * log(y);
  }
  if (z == 0) {
    if (c == 0) {
      p3 = log(1.0);
    }
    else {
      return -1;
    }
  }
  else {
    p3 = c * log(z);
  }
  return p1 + p2 + p3;
}

void source() {
  ld s;
  cin >> s;
  ld x, y, z;
  cin >> x >> y >> z;
  ld l = 0, r = s;
  for (int iter = 0; iter < 228; iter++) {
    ld m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
    ld l1 = 0, r1 = s - m1, l2 = 0, r2 = s - m2;
    for (int iter2 = 0; iter2 < 228; iter2++) {
      ld mm1 = l1 + (r1 - l1) / 3.0, mm2 = r1 - (r1 - l1) / 3.0;
      if (get(x, y, z, m1, mm1, s - m1 - mm1) > get(x, y, z, m1, mm2, s - m1 - mm2)) {
        r1 = mm2;
      }
      else {
        l1 = mm1;
      }
    }
    for (int iter2 = 0; iter2 < 228; iter2++) {
      ld mm1 = l2 + (r2 - l2) / 3.0, mm2 = r2 - (r2 - l2) / 3.0;
      if (get(x, y, z, m2, mm1, s - m2 - mm1) > get(x, y, z, m2, mm2, s - m2 - mm2)) {
        r2 = mm2;
      }
      else {
        l2 = mm1;
      }
    }
    if (get(x, y, z, m1, l1, s - m1 - l1) > get(x, y, z, m2, l2, s - m2 - l2)) {
      r = m2;
    }
    else {
      l = m1;
    }
  }
  ld l1 = 0, r1 = s - l;
  for (int iter2 = 0; iter2 < 228; iter2++) {
    ld mm1 = l1 + (r1 - l1) / 3.0, mm2 = r1 - (r1 - l1) / 3.0;
    if (get(x, y, z, l, mm1, s - l - mm1) > get(x, y, z, l, mm2, s - l - mm2)) {
      r1 = mm2;
    }
    else {
      l1 = mm1;
    }
  }
  cout << fixed << setprecision(10) << l << ' ' << l1 << ' ' << s - l - l1;
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