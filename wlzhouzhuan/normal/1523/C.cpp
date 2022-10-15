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

const int N = 1000005;

int a[N], stk[N], top, n;

void solve() {
  n = read(), top = 0;
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) {
    if (a[i] == 1) stk[++top] = 1;
    else {
      while (stk[top] != a[i] - 1) top--;
      stk[top]++;
    }
    for (int j = 1; j < top; j++) {
      printf("%d.", stk[j]);
    }
    printf("%d\n", stk[top]);
  }
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}