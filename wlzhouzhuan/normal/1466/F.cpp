// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 5000005;
const int mod = 1e9 + 7;
vector<int> V[N];
int ans[N], cnt;
int n, m, f[N], flg[N];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    int len = read();
    V[i].resize(len);
    for (auto &v: V[i]) v = read();
    if (V[i].size() == 2) {
      int x = find(V[i][0]), y = find(V[i][1]);
      if (x == y || (flg[x] && flg[y])) continue;
      else {
        f[x] = y, flg[y] |= flg[x], ans[++cnt] = i;
      }
    } else {
      int x = find(V[i][0]);
      if (flg[x]) continue;
      flg[x] = 1, ans[++cnt] = i;
    }
  }
  int zz = 1;
  for (int c = 1; c <= cnt; c++) zz = 2 * zz % mod;
  printf("%d %d\n", zz, cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}