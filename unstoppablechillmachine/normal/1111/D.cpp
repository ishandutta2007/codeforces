#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int BINF = 1e18 + 10;

const int ALPHA = 52;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int dp[N][ALPHA], cnt[ALPHA], calc[ALPHA][ALPHA], fa[N], inv_fa[N], n;

int f(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a';
  }
  return 26 + int(c - 'A');
}

inline int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}
inline int sum(int a, int b) {
  return (a + b) % MOD;
}
int b_pow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return mult(a, b_pow(a, b - 1));
  }
  int c = b_pow(a, b >> 1);
  return mult(c, c);
}

inline void g1(int ind, int c) {
  if (!c) {
    return;
  }
  for (int i = c; i <= n; i++) {
    sub(dp[i][ind], dp[i - c][ind]);
  }
}

inline void g2(int ind, int c) {
  if (!c) {
    return;
  }
  for (int i = n - c; i >= 0; i--) {
    add(dp[i + c][ind], dp[i][ind]);
  }
}

void source() {
  string s;
  cin >> s;
  for (auto it : s) {
    cnt[f(it)]++;
  }
  n = SZ(s) / 2;
  fa[0] = 1;
  inv_fa[0] = b_pow(fa[0], MOD - 2);
  for (int i = 1; i <= 2 * n; i++) {
    fa[i] = mult(fa[i - 1], i);
    inv_fa[i] = b_pow(fa[i], MOD - 2);
  }
  int W = mult(fa[n], fa[n]);
  for (int i = 0; i < 52; i++) {
    if (cnt[i]) W = mult(W, inv_fa[cnt[i]]);
  }
  for (int letter = 0; letter < ALPHA; letter++) {
    dp[0][letter] = 1;
    for (int i = 0; i < ALPHA; i++) {
      if (i == letter || !cnt[i]) {
        continue;
      }
      g2(letter, cnt[i]);
    }
    for (int letter2 = 0; letter2 < ALPHA; letter2++) {
      if (letter == letter2) {
        calc[letter][letter2] = mult(2, mult(dp[n][letter], W));
      }
      else {
        if (cnt[letter] + cnt[letter2] > n) {
          continue;
        }
        g1(letter, cnt[letter2]);
        calc[letter][letter2] = mult(2, mult(dp[n][letter], W));
        g2(letter, cnt[letter2]);
      }
    }
  }  
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int p1, p2;
    cin >> p1 >> p2;
    p1--, p2--;
    int a = f(s[p1]), b = f(s[p2]);
    cout << calc[a][b] << '\n';
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
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}