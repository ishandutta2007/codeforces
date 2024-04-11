// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

int lg[20005];
int Max[20005][15], r[20005];
// f[i][j][k]:  i skip  j  2^k  
int f[20005][31][15], n, q, m;

int MAX(int x, int y) {
  return r[x] > r[y] ? x : y; 
}
int qmax(int l, int r) {
  int len = lg[r - l + 1];
  return MAX(Max[l][len], Max[r - (1 << len) + 1][len]);
}

int main() {
  n = read(), q = read(), m = 30;
  lg[1] = 0;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) r[i] = min(i + read(), n), Max[i][0] = i;
  for (int j = 1; j < 15; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      Max[i][j] = MAX(Max[i][j - 1], Max[i + (1 << j - 1)][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j][0] = min(r[i] + j, n);
    }
  }
  for (int k = 1; k < 15; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        // calc f[i][j][k]
        for (int l = 0; l <= j; l++) {
          int who = qmax(i, f[i][l][k - 1]);
          ckmax(f[i][j][k], f[who][j - l][k - 1]);
        }
      }
    }
  }
  while (q--) {
    int L = read(), R = read(), k = read();
    if (L == R) { puts("0"); continue; }
    static int far[31], tmp[31];
    int ans = 0;
    for (int i = 0; i <= k; i++) far[i] = L;
    for (int i = 14; i >= 0; i--) {
      int ok = 0;
      for (int j = 0; j <= k; j++) {
        tmp[j] = 0;
        for (int l = 0; l <= j; l++) {
          int who = qmax(L, far[l]);
          ckmax(tmp[j], f[who][j - l][i]);
        }
        if (tmp[j] >= R) {
          ok = 1;
          break;
        }
      }
      if (!ok) {
        ans += 1 << i;
        memcpy(far, tmp, 4 * (k + 1));
      }
    }
    print(ans + 1, '\n');
  }
  return 0;
}