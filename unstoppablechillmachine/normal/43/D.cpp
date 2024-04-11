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

void source() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    if (m == 2) {
      cout << 0 << '\n';
      cout << "1 1\n" << "1 2\n" << "1 1\n";
    }
    else {
      cout << 1 << '\n';
      cout << 1 << ' ' << m << " 1 1\n";
      for (int i = 1; i <= m; i++) {
        cout << 1 << ' ' << i << '\n';
      }
      cout << "1 1";
    }
    exit(0);
  }
  if (m == 1) {
    if (n == 2) {
      cout << 0 << '\n';
      cout << "1 1\n" << "2 1\n" << "1 1\n";
    }
    else {
      cout << 1 << '\n';
      cout << n << ' ' << 1 << " 1 1\n";
      for (int i = 1; i <= n; i++) {
        cout << i << ' ' << 1 << '\n';
      }
      cout << "1 1";
    }
    exit(0);  
  }
  if (n % 2 == 0) {
    cout << 0 << '\n';
    cout << "1 1\n";
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        for (int j = 2; j <= m; j++) {
          cout << i << ' ' << j << '\n';
        }
      }
      else {
        for (int j = m; j >= 2; j--) {
          cout << i << ' ' << j << '\n';
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      cout << i << ' ' << 1 << '\n';
    }
    exit(0);
  }
  if (m % 2 == 0) {
    cout << 0 << '\n';
    cout << "1 1\n";
    for (int i = 1; i <= m; i++) {
      if (i & 1) {
        for (int j = 2; j <= n; j++) {
          cout << j << ' ' << i << '\n';
        }
      }
      else {
        for (int j = n; j >= 2; j--) {
          cout << j << ' ' << i << '\n';
        }
      }
    }
    for (int i = m; i >= 1; i--) {
      cout << 1 << ' ' << i << '\n';
    }
    exit(0);
  }
  cout << "1\n";
  cout << n << ' ' << m << " 1 1\n";
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      for (int j = 1; j <= m; j++) {
        cout << i << ' ' << j << '\n';
      }
    }
    else {
      for (int j = m; j >= 1; j--) {
        cout << i << ' ' << j << '\n';
      }
    }
  }
  cout << "1 1";  
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