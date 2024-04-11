// Author: wlzhouzhuan
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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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
int cnt[10];
bool check(ll x) {
  memset(cnt, 0, sizeof(cnt));
  ll _x = x;
  while (_x) cnt[_x % 10] = 1, _x /= 10;
  for (int i = 1; i < 10; i++) {
    if (cnt[i] && x % i != 0) return false;
  }
  return true;
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    long long n;
    scanf("%lld", &n);
    while (!check(n)) n++;
    printf("%lld\n", n);
  }
  return 0;
}