//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
//#define int ll
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

unordered_map<int, int> was;
int lst;

_ int get(int x) {
  if (was.find(x) == was.end()) {
    return was[x] = lst++;
  }
  return was[x];
}

const int N = 5e5 + 10;
pair<int, int> p[N];

pair<int, int> find(int v) {
  if (p[v].F == v) {
    return p[v];
  }
  pair<int, int> kek = find(p[v].F);
  p[v].F = kek.F;
  p[v].S ^= kek.S;
  return p[v];
}

void merge(int l, int r, int x) {
  pii par1 = find(l), par2 = find(r);
  if (par1.F == par2.F) {
    return;
  }
  p[par2.F] = {par1.F, x ^ par1.S ^ par2.S};
}

int calc(int l, int r) {
  pii par1 = find(l), par2 = find(r);
  return (par1.F == par2.F ? par1.S ^ par2.S : -1);
}

void source() {
  for (int i = 0; i <= 5e5; i++) {
    p[i] = {i, 0};
  }
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l1, r1, xr1, ff = (ans == -1 ? 1 : ans);
      cin >> l1 >> r1 >> xr1;
      int l = l1 ^ ff, r = r1 ^ ff, xr = xr1 ^ ff;
      if (l > r) {
        swap(l, r);
      }
      r++;
      l = get(l), r = get(r);
      merge(l, r, xr);
    }
    else {
      int l1, r1, ff = (ans == -1 ? 1 : ans);
      cin >> l1 >> r1;
      int l = l1 ^ ff, r = r1 ^ ff;
      if (l > r) {
        swap(l, r);
      }
      r++;
      l = get(l), r = get(r);
      ans = calc(l, r);
      cout << ans << '\n';
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