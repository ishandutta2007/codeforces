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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int MOD = 998244353;

int b_pow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return (a * b_pow(a, b - 1)) % MOD;
  }
  int c = b_pow(a, b >> 1);
  return (c * c) % MOD;
}

int inv(int a) {
  return b_pow(a, MOD - 2);
}

int mult(int a, int b) {
  return (a * b) % MOD;
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

struct fen {
  vector<int> t;
  int n;
  fen(int _n) {
    n = _n;
    t.resize(n + 10);
  }
  void update(int v) {
    for (; v <= n; v += v & (-v)) {
      t[v]++;
    }
  }
  int get(int v) {
    int res = 0;
    for (; v > 0; v -= v & (-v)) {
      res += t[v];
    }
    return res;
  }
};

void source() {
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  int cnt = 0;
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == -1) {
      cnt++;
    }
    else {
      used[arr[i]] = true;
    }
  }
  int perm = 1, perm2 = 1;
  for (int  i= 2; i <= cnt; i++) {
    perm = mult(perm, i);
    if (i < cnt) {
      perm2 = mult(perm2, i);
    }
  }
  vector<int> h;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      h.pb(i);
    }
  }
  fen A(n);
  int cur = 0, ost = cnt;
  for (int i = 1; i <= n; i++) {
    if (arr[i] > 0) {
      int kek = n - arr[i] + 1;
      add(cur, mult(A.get(kek - 1), perm));
      A.update(kek);
      int cc = upper_bound(all(h), arr[i]) - h.begin();
      if (cnt) {
        add(cur, mult(mult(perm2, ost), cc));
        add(cur, mult(mult(perm2, cnt - ost), cnt - cc));
      }
    }
    else {
      ost--;
    }
  }
  if (cnt) {
    add(cur, mult((cnt * (cnt - 1) / 2) % MOD, mult(perm, inv(2))));
  }
  cout << mult(cur, inv(perm));
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