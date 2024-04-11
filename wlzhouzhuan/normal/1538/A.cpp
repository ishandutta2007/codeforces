// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx")
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

int a[105], n;

void solve() {
  n = read();
  int pos1 = 0, pos2 = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (i == 1) pos1 = pos2 = 1;
    else {
      if (a[i] > a[pos1]) pos1 = i;
      if (a[i] < a[pos2]) pos2 = i;
    }
  }
  if (pos1 > pos2) swap(pos1, pos2);
  printf("%d\n", min(min(pos2, n - pos1 + 1), pos1 + n - pos2 + 1));
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}