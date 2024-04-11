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

const int N = 100005;

struct node {
  int x, y;
  friend bool operator < (const node &a, const node &b) {
    return a.x < b.x;
  } 
} a[N];
int n;
ll ans;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read(), a[i].y = read();
    ans += a[i].y, a[i].y += a[i].x;
  }
  sort(a + 1, a + n + 1);
  int cur = a[1].y;
  for (int i = 1; i <= n; i++) {
    while (i <= n && a[i].x <= cur) {
      cur = max(cur, a[i++].y);
    }
    if (i <= n) {
      ans += a[i].x - cur;
      cur = max(cur, a[i].y);
    }
  }
  print(ans, '\n');
  return 0;
}