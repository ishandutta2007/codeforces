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
  int fn, fm, fk;
  T() {};
  T(int n, int m, int k) : fn(n), fm(m), fk(k) {};
};

const int N = 110;
int dp[N][N][N];
T from[N][N][N];
int go[N][26], z[N];

void precalc(string s) {
  int len = SZ(s);
  z[0] = len;
  for (int j = 1; j < len; j++) {
    int kek = 0;
    while (j + kek < len && s[j + kek] == s[kek]) {
      kek++;
    }
    z[j] = kek;
    debug(z[j]);
  }
  string cur = "" + s[0];
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < 26; j++) {
      if (s[i] - 'A' == j) {
        continue;
      }
      cur += char('A' + j);
      for (int x = i; x > 0; x--) {
        bool ok = true;
        for (int y = 0; y < x; y++) {
          if (s[y] != cur[SZ(cur) - x + y]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          go[i][j] = x;
          break;
        }
      }
      cur.pop_back();
    }
    cur += s[i];
  }
}

void source() {
  string a, b, c;
  cin >> a >> b >> c;
  precalc(c);
  int n = SZ(a), m = SZ(b), k = SZ(c);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int p = 0; p <= k; p++) {
        dp[i][j][p] = -INF;
      }
    }
  }
  dp[0][0][0] = 0;
  int ans = 0;
  T cur(0, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int p = 0; p < k; p++) {
        if (dp[i][j][p] > dp[i + 1][j][p]) {
          dp[i + 1][j][p] = dp[i][j][p];
          from[i + 1][j][p].fn = i;
          from[i + 1][j][p].fm = j;
          from[i + 1][j][p].fk = p;
        }
        if (dp[i][j][p] > dp[i][j + 1][p]) {
          dp[i][j + 1][p] = dp[i][j][p];
          from[i][j + 1][p].fn = i;
          from[i][j + 1][p].fm = j;
          from[i][j + 1][p].fk = p;
        }
        if (a[i] == b[j]) {
          if (a[i] == c[p]) {
            if (p + 1 == k) {
              continue;
            }
            if (dp[i][j][p] + 1 > dp[i + 1][j + 1][p + 1]) {
              dp[i + 1][j + 1][p + 1] = dp[i][j][p] + 1;
              from[i + 1][j + 1][p + 1].fn = i;
              from[i + 1][j + 1][p + 1].fm = j;
              from[i + 1][j + 1][p + 1].fk = p;
            }
          }
          else {
            int to = go[p][a[i] - 'A'];
            if (dp[i][j][p] + 1 > dp[i + 1][j + 1][to]) {
              dp[i + 1][j + 1][to] = dp[i][j][p] + 1;
              from[i + 1][j + 1][to].fn = i;
              from[i + 1][j + 1][to].fm = j;
              from[i + 1][j + 1][to].fk = p;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int p = 0; p < k; p++) {
        if (dp[i][j][p] > ans) {
          ans = dp[i][j][p];
          cur.fn = i;
          cur.fm = j;
          cur.fk = p;
        }
      }
    }
  }
  string res;
  while (cur.fn && cur.fm) {
    T cur2 = from[cur.fn][cur.fm][cur.fk];
    if (cur2.fn < cur.fn && cur2.fm < cur.fm) {
      res += a[cur2.fn];
    }
    cur = cur2;
  }
  reverse(all(res));
  cout << (res.empty() ? "0" : res);
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