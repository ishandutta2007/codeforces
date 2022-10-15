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

ll x, y, a, b;
void solve() {
  scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
  if (a > b) swap(a, b);
  if (a == b) {
    printf("%lld\n", min(x, y) / a);
    return ; 
  }
  ll l = 0, r = 2e9;
  while (l < r) {
    ll mid = l + r + 1 >> 1;
    ll least = (b * mid - x + (b - a - 1)) / (b - a);
    least = max(0ll, least);
    if (y - a * mid < 0) {
      r = mid - 1;
      continue;
    }
    ll most = (y - a * mid) / (b - a);
    most = min(most, mid);
    if (least <= most) l = mid;
    else r = mid - 1;
  }
  printf("%lld\n", l);
}

int main() {
  int T = read();
  while (T--) solve(); 
  return 0;
}