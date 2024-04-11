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

const int N = 110;
int a[N], b[N], cur[N], cur2[N], n;

void get1() {
  for (int i = 1; i <= n; i++) {
    cur2[i] = cur[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    cur[i] = cur2[i];
  }
}

void get2() {
  for (int i = 1; i <= n; i++) {
    cur2[a[i]] = cur[i];
  }
  for (int i = 1; i <= n; i++) {
    cur[i] = cur2[i];
  }
}

bool is_equal() {
  for (int i = 1; i <= n; i++) {
    if (cur[i] != b[i]) {
      return false;
    }
  }
  return true;
}

void source() {
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool okk = false;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] != i) {
      okk = true;
    }
  }
  if (!okk) {
    cout << "NO";
    exit(0);
  }
  for (int x = 0; x <= k; x++) {
    int y = k - x;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      cur[i] = i;
    }
    for (int i = 0; i < min(x, y); i++) {
      get1();
      if (is_equal()) {
        ok = false;
      }
      get2();
      if (is_equal() && (i + 1) * 2 < k) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      ok = true;
      for (int i = 1; i <= n; i++) {
        cur[i] = i;
      }
      for (int i = 0; i < min(x, y); i++) {
        get2();
        if (is_equal()) {
          ok = false;
          break;
        }
        get1();
        if (is_equal() && (i + 1) * 2 < k) {
          ok = false;
        }
      }
    }
    if (x > y) {
      for (int i = 0; i < x - y; i++) {
        if (is_equal()) {
          ok = false;
          break;
        }
        get1();
      }
    }
    else if (x < y) {
      for (int i = 0; i < y - x; i++) {
        if (is_equal()) {
          ok = false;
          break;
        }
        get2();
      }
    }
    if (!is_equal()) {
      ok = false;
    }
    if (ok) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
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