// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define fir first
#define sec second

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b; 
}

const int N = 2005;
const ll mod = 1e9 + 7;

struct Edge {
  int to, nxt, val;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int w) {
  edge[++tot] = {v, head[u], w};
  head[u] = tot;
}

// dp[i][j] ji 
ll mx[N], dp[N][N], ans;
int n, m, q;

int main() {
  n = read(), m = read(), q = read();
  for (rint i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    add(u, v, w);
    add(v, u, w);
    ckmax(mx[u], w);
    ckmax(mx[v], w);
  }
  
  for (rint i = 0; i <= n; i++) {
    for (rint j = 0; j <= m; j++) {
      dp[i][j] = -1e18;
    }
  }
  dp[1][0] = 0;
  for (rint j = 1; j <= m; j++) {
    ll res = 0;
    for (rint i = 1; i <= n; i++) {
      for (rint t = head[i]; t; t = edge[t].nxt) {
        int v = edge[t].to;
        ckmax(dp[i][j], dp[v][j - 1] + edge[t].val);
      }
      ckmax(res, dp[i][j]);
    }
    (ans += res) %= mod;
  }
  
  for (rint rnd = 1; rnd <= q - m; rnd++) {
    ll tmp = 0;
    int pos = 0;
    for (rint i = 1; i <= n; i++) {
      if (dp[i][m] <= 0) continue;
      ll newDp = dp[i][m] + mx[i] * rnd;
      if (newDp > tmp) {
        tmp = newDp;
        pos = i;
      }
    }
    int nxt = q - m;
    for (rint i = 1; i <= n; i++) {
      if (dp[i][m] <= 0) continue;
      if (i == pos || mx[i] <= mx[pos] || dp[pos][m] <= dp[i][m]) continue;
      int newTurns = (dp[pos][m] - dp[i][m]) / (mx[i] - mx[pos]);
      if (newTurns >= rnd) nxt = min(nxt, newTurns);
    } 
    ll len = nxt - rnd;
    /*
      tmp
      tmp + mx[pos]
      ...
      tmp + len * mx[pos]
    */
    ans = (ans + 1ll * (len + 1) * (tmp % mod) % mod) % mod;
    ans = (ans + (1 + len) * len / 2 % mod * mx[pos] % mod) % mod;
    rnd = nxt;
  }
  printf("%lld\n", ans);
  return 0;
}