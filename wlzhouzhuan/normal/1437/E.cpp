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

const int N = 1000005;
int dp[N], a[N], n, k;
int b[N], ban[N], tot;

struct Bit {
  int c[N];
  void init() {
    memset(c, -0x3f, sizeof(c));
  }
  void clear(int x) {
    while (x <= tot) {
      c[x] = -1e9;
      x += x & -x;
    }
  }
  void add(int x, int dlt) {
    while (x <= tot) {
      c[x] = max(c[x], dlt);
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = -1e9;
    while (x > 0) {
      ret = max(c[x], ret);
      x ^= x & -x;
    }
    return ret;
  }
} bit;
int LIS(int l, int r) {
  for (int i = l; i <= r; i++) {
    if (a[i] < a[l]) {
      dp[i] = 0;
      continue;
    }
    dp[i] = max(0, bit.qry(a[i])) + 1;
    bit.add(a[i], dp[i]); 
  }
  for (int i = l; i <= r; i++) bit.clear(a[i]);
  return dp[r];
}
int main() {
  bit.init();
  n = read(), k = read();
  a[0] = -2e9, a[n + 1] = 2e9;
  for (int i = 1; i <= n; i++) a[i] = read() - i;

  for (int i = 0; i <= n + 1; i++) b[++tot] = a[i];
  sort(b + 1, b + tot + 1), tot = unique(b + 1, b + tot + 1) - (b + 1);
  for (int i = 0; i <= n + 1; i++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
 
  for (int i = 1; i <= k; i++) {
    int x = read();
    ban[x] = 1;
  }
  vector<int> b;
  b.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (ban[i]) b.push_back(i);
  }
  b.push_back(n + 1);
  
  int ans = 0;
  for (int i = 0; i < b.size() - 1; i++) {
    if (a[b[i + 1]] < a[b[i]]) {
      puts("-1"); return 0;
    }
    int lis = LIS(b[i], b[i + 1]);
    ans += b[i + 1] - b[i] + 1 - lis;  
  }
  printf("%d\n", ans);
  return 0;
}