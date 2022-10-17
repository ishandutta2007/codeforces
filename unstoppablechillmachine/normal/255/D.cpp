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

int get(int l, int r) {
  if (l > r) {
    swap(l, r);
  }
  return r * (r + 1) / 2 - l * (l - 1) / 2;
}

int solve(int a, int b, int lim) {
  int res = 0;
  if (a > lim) {
    if (b >= lim) {
      res += lim * (a - b + 1);
    }
    else {
      res += get(b, lim) + lim * (a - lim);
    }
  }
  else {
    res += get(a, b);
  }
  return res;
}

void source() {
  int n, x, y, need;
  cin >> n >> x >> y >> need;
  if (need <= 1) {
    cout << 0;
    exit(0);
  }
  int l = 0, r = 2 * n + 10;
  int mx_up = n - y + 1, mx_down = y;
  while (r - l > 1) {
    int mid = (l + r) / 2, sum = 0;
    int left = max(x - mid, 1ll), right = min(x + mid, n);
    int a = mid + 1, vl = a - (x - left), vr = a - (right - x);
    sum = solve(a, vl, mx_up) + solve(a, vr, mx_up) - min(mx_up, a);
    sum += solve(a, vl, mx_down) + solve(a, vr, mx_down) - min(mx_down, a);
    sum -= right - left + 1;
    if (sum >= need) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  cout << r;
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