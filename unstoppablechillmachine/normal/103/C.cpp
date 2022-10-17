//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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
  int n, k, p;
  cin >> n >> k >> p;
  int zeros = n - k;
  if (k <= zeros) {
    int cnt = zeros - k + 1;
    bool sw = false;
    if (cnt % 2 == 0 && cnt < zeros) {
      sw = true;
    }
    for (int i = 0; i < p; i++) {
      int x;
      cin >> x;
      if (x <= cnt) {
        cout << '.';
      }
      else if (x == cnt + 1) {
        cout << (sw ? '.' : 'X');
      }
      else if (x == cnt + 2) {
        cout << (sw ? 'X' : '.');
      }
      else if (x < n) {
        x -= cnt;
        if (!sw) {
          cout << (x & 1 ? 'X' : '.');
        }
        else {
          cout << (x & 1 ? '.' : 'X');
        }
      }
      else {
        if (sw) {
          cout << 'X';
        }
        else {
          x -= cnt;
          cout << (x & 1 ? 'X' : '.');  
        }
      }
    }
  }
  else {
    for (int i = 0; i < p; i++) {
      int x;
      cin >> x;
      if (zeros * 2 >= x) {
        cout << (x & 1 ? '.' : 'X');
      }
      else {
        cout << 'X';
      }
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