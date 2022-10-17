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

int mult(int a, int b) {
  return (a * b) % MOD;
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

const int N = 1e5 + 10;
int fa[N], inv_fa[N];

int C(int n, int k) {
  if (k > n || k < 0 || n < 0) {
    return 0;
  }
  return mult(mult(fa[n], inv_fa[k]), inv_fa[n - k]);
}

int f(int sum, int cnt) {
  if (sum == 0) {
    return 1;
  }
  return C(sum + cnt - 1, cnt - 1);
}

int get(int sum, int cnt, int up_lim) {
  int res = 0;
  for (int i = 0; i <= cnt; i++) {
    if (i * up_lim > sum) {
      break;
    }
    if (i & 1) {
      sub(res, mult(C(cnt, i), f(sum - up_lim * i, cnt)));
    }
    else {
      add(res, mult(C(cnt, i), f(sum - up_lim * i, cnt)));
    }
  }
  return res;
}

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

int inverse(int a) {
  return b_pow(a, MOD - 2);
}

void source() {
  int n, sum, mn;
  cin >> n >> sum >> mn;
  fa[0] = 1;
  for (int i = 1; i < N; i++) {
    fa[i] = mult(fa[i - 1], i);
  }
  for (int i = 0; i < N; i++) {
    inv_fa[i] = inverse(fa[i]);
  }
  int all = f(sum - mn, n), good = 0;
  for (int i = mn; i <= sum; i++) {
    for (int j = 1; j <= n; j++) {
      if (i * j > sum) {
        break;
      }
      add(good, mult(C(n - 1, j - 1), mult(get(sum - i * j, n - j, i), inverse(j))));
    }
  }
  cout << mult(good, inverse(all));
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