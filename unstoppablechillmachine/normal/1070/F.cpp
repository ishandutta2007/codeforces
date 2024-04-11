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

const int N = 5010;
pii par[N];
int f[N];

void add(int x) {
  int cur_block = x / 70;
  par[cur_block].F += x;
  par[cur_block].S++;
  f[x]++;
}

void del(int x) {
  int cur_block = x / 70;
  par[cur_block].F -= x;
  par[cur_block].S--;
  f[x]--;
}

int get(int cnt) {
  int res = 0;
  for (int i = 5000 / 70; i >= 0; i--) {
    if (par[i].S > cnt) {
      int r = i * 70 + 69, l = i * 70;
      for (int j = r; j >= l; j--) {
        if (f[j] >= cnt) {
          return res + cnt * j;
        }
        res += f[j] * j;
        cnt -= f[j];
      }
    }
    else {
      res += par[i].F;
      cnt -= par[i].S;
    }
    if (!cnt) {
      break;
    }
  }
  return res;
}

void source() {
  int n;
  cin >> n;
  int cnt = 0, sum = 0;
  vector<int> arr1, arr2, arr3;
  for (int i = 0; i < n; i++) {
    string type;
    int kek;
    cin >> type >> kek;
    if (type == "11") {
      cnt++;
      sum += kek;
    }
    else {
      add(kek);
    }
    if (type == "10") {
      arr1.pb(kek);
    }
    if (type == "01") {
      arr2.pb(kek);
    }
    if (type == "00") {
      arr3.pb(kek);
    }
  }
  sort(rall(arr1));
  sort(rall(arr2));
  sort(rall(arr3));
  int ans = sum, pnt1 = 0, pnt2 = 0;
  for (int i = max(cnt, 1); i <= n; i++) {
    int need = (i + 1) / 2 - cnt;
    if (SZ(arr1) < need || SZ(arr2) < need) {
      break;
    }
    while (pnt1 < need) {
      sum += arr1[pnt1];
      del(arr1[pnt1++]);
    }
    while (pnt2 < need) {
      sum += arr2[pnt2];
      del(arr2[pnt2++]);
    }
    int take = cnt + 2 * max(need, 0);
    if (take <= i) {
      ans = max(ans, sum + get(i - take));
    }
  }
  cout << ans;
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