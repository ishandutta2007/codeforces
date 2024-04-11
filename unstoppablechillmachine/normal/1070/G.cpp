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
  int F, S, num;
};

bool cmp(T a, T b) {
  return a.F < b.F;
}

const int N = 110;
bool can[N][N], pref[N][N], suf[N][N];
int from1[N][N], from2[N][N];

void source() {
  int n, m;
  cin >> n >> m;
  vector<T> arr(m);
  for (int i = 0; i < m; i++) {
    cin >> arr[i].F >> arr[i].S;
    arr[i].num = i + 1;
    arr[i].F--;
  }
  sort(all(arr), cmp);
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }
  for (int i = 0; i < m; i++) {
    int cur = arr[i].S;
    can[i][arr[i].F] = true;
    for (int j = arr[i].F; j < n; j++) {
      cur += a[j];
      if (cur < 0) {
        break;
      }
      can[i][j] = true;
    }
    cur = arr[i].S;
    for (int j = arr[i].F - 1; j >= 0; j--) {
      cur += a[j];
      if (cur < 0) {
        break;
      }

      can[i][j] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[0].F <= i && can[0][i]) {
      pref[0][i] = true;
      from1[0][i] = 0;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = arr[i].F; j < n; j++) {
      if (pref[i - 1][j]) {
        from1[i][j] = from1[i - 1][j];
        pref[i][j] = true;
      }
      if (pref[i - 1][arr[i].F] && can[i][j]) {
        from1[i][j] = i;
        pref[i][j] = true;
      }
    }
  }
  for (int i = arr[m - 1].F; i >= 0; i--) {
    if (can[m - 1][i]) {
      suf[m - 1][i] = true;
      from2[m - 1][i] = m - 1;
    }
  }
  for (int i = m - 2; i >= 0; i--) {
    for (int j = arr[i].F; j >= 0; j--) {
      if (suf[i + 1][j]) {
        from2[i][j] = from2[i + 1][j];
        suf[i][j] = true;
      }
      if (can[i][j] && suf[i + 1][arr[i].F]) {
        from2[i][j] = i;
        suf[i][j] = true;
      }
    }
  }
  int kek = -1, l = -1;
  for (int i = 0; i < n; i++) {
    int mx = -1;
    for (int j = 0; j < m; j++) {
      if (arr[j].F <= i) {
        mx = j;
      }
    }
    if (mx == -1) {
      if (suf[0][i]) {
        kek = i;
        l = -1;
        break;
      }
    }
    else if (mx == m - 1) {
      if (pref[m - 1][i]) {
        kek = i;
        l = m - 1;
      }
    }
    else {
      if (pref[mx][i] && suf[mx + 1][i + 1]) {
        kek = i;
        l = mx;
      }
    }
  }
  if (kek == -1) {
    cout << -1;
    exit(0);
  }
  int kok = kek;
  vector<int> ans;
  int r = l + 1;
  while (l >= 0) {
    int xx = from1[l][kek];
    ans.pb(arr[xx].num);
    for (int i = xx + 1; i <= l; i++) {
      ans.pb(arr[i].num);
    }
    kek = arr[xx].F;
    l = xx - 1;
  }
  kek = kok;
  while (r < m) {
    int xx = from2[r][kek + 1];
    ans.pb(arr[xx].num);
    for (int i = r; i < xx; i++) {
      ans.pb(arr[i].num);
    }
    kek = arr[xx].F;
    r = xx + 1;
  }
  cout << kok + 1 << '\n';
  for (auto it : ans) {
    cout << it << ' ';
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