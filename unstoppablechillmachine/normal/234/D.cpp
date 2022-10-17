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

struct T {
  string name;
  int cnt, mn, mx;
};

void source() {
  int n, m;
  cin >> n >> m;
  vector<bool> fav(n + 1);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    fav[x] = true;
  }
  int cnt;
  cin >> cnt;
  vector<T> arr(cnt);
  for (int i = 0; i < cnt; i++) {
    cin >> arr[i].name >> arr[i].cnt;
    int kek = 0, lol = 0;
    for (int j = 0; j < arr[i].cnt; j++) {
      int x;
      cin >> x;
      if (!x) {
        lol++;
      }
      if (fav[x]) {
        kek++;
      }
    }
    arr[i].mn = kek + max(0, (lol - (n - m - (arr[i].cnt - kek - lol))));
    arr[i].mx = min(kek + lol, m);
    //cout << arr[i].mn << ' ' << arr[i].mx << '\n';
  }
  for (int i = 0; i < cnt; i++) {
    bool ok1 = false, ok2 = true;
    for (int j = 0; j < cnt; j++) {
      if (i == j) {
        continue;
      }
      if (arr[j].mn > arr[i].mx) {
        ok1 = true;
      }
      if (arr[j].mx > arr[i].mn) {
        ok2 = false;
      }
    }
    if (ok1) {
      cout << 1 << '\n';
    }
    else if (ok2) {
      cout << 0 << '\n';
    }
    else {
      cout << 2 << '\n';
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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