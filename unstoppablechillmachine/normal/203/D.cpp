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

struct T {
  ld x, y, z;
  T() {};
  T(ld _x, ld _y, ld _z) : x(_x), y(_y), z(_z) {};
  T sum(T delta) {
    return T(x + delta.x, y + delta.y, z + delta.z);
  }
};

const ld eps = 1e-7;

void source() {
  ld a, b, m;
  cin >> a >> b >> m;
  ld vx, vy, vz;
  cin >> vx >> vy >> vz;
  T cur(a / 2.0, m, 0);
  T V(vx, vy, vz);
  while (abs(cur.y) > eps) {
    ld time1, time2;
    if (V.x == 0) {
      time1 = INF;
    }
    else {
      if (V.x > 0) {
        time1 = (a - cur.x) / V.x;
      }
      else {
        time1 = -cur.x / V.x;
      }
    }
    if (V.z == 0) {
      time2 = INF;
    }
    else {
      if (V.z > 0) {
        time2 = (b - cur.z) / V.z;
      }
      else {
        time2 = -cur.z / V.z;
      }
    }
    if (cur.y + V.y * min(time1, time2) > eps) {
      T V2(V.x * min(time1, time2), V.y * min(time1, time2), V.z * min(time1, time2));
      cur = cur.sum(V2);
      if (time1 < time2) {
        V.x *= -1;
      }
      else {
        V.z *= -1;
      }
    }
    else {
      ld time = -cur.y / V.y;
      T V2(V.x * time, V.y * time, V.z * time);
      cur = cur.sum(V2);
      break;
    }
  } 
  cout << fixed << setprecision(10) << cur.x << ' ' << cur.z; 
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