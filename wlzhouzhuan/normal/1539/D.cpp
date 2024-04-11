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
#define int long long
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

const int N = 100005;
struct node { int num, lim; } a[N];
int n;

signed main() {
  n = read();
  rep(i, 1, n) a[i].num = read(), a[i].lim = read();
  sort(a + 1, a + n + 1, [&](node x, node y) {
    return x.lim < y.lim;
  });
  int ans = 0;
  for (int i = 1, j = n, now = 0; i <= j; i++) {
    while (j >= i && now < a[i].lim) {
      int need = min(a[i].lim - now, a[j].num);
      a[j].num -= need, now += need, ans += 2 * need;
      if (!a[j].num) j--;
    }
//    printf("i =%d,ans=%d\n",i,ans);
    if (j < i) break;
    ans += a[i].num, now += a[i].num;
  }
  print(ans, '\n');
}