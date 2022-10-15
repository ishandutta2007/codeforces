// Author: wlzhouzhuan
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

vector<pii> a[2]; 
int n;

int tell(int num, int x, int y) {
  printf("%d %d %d\n", num, x, y), fflush(stdout);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[(i + j) & 1].pb({i, j});
    }
  }
  while (SZ(a[0]) && SZ(a[1])) {
    int t; scanf("%d", &t);
    if (t == 1) {
      tell(2, a[1].back().fir, a[1].back().sec);
      a[1].pop_back();
    } else {
      tell(1, a[0].back().fir, a[0].back().sec);
      a[0].pop_back();
    }
  }
  while (SZ(a[0])) {
    int t; scanf("%d", &t);
    if (t == 1) t = 3;
    else t = 1;
    tell(t, a[0].back().fir, a[0].back().sec);
    a[0].pop_back();
  }
  while (SZ(a[1])) {
    int t; scanf("%d", &t);
    if (t == 2) t = 3;
    else t = 2;
    tell(t, a[1].back().fir, a[1].back().sec);
    a[1].pop_back();
  }
  return 0;
}