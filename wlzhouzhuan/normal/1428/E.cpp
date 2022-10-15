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

const int N = 100005;

long long a[N], ans = 0ll;
int n, k;

ll sqr(ll x) { return x * x; }
ll fuck(ll x, ll y) {
  ll p1 = x / y, p2 = x % y;
  return (y - p2) * sqr(p1) + p2 * sqr(p1 + 1);
} 
struct node {
  int x, y;
  long long delta;
  friend bool operator < (const node &x, const node &y) {
    return x.delta > y.delta;
  }
};
priority_queue <node> pq;

int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    ans += a[i] * a[i];
    if (a[i] > 1)
      pq.push({i, 2, fuck(a[i], 2) - fuck(a[i], 1)});
  }
  k -= n;
  while (k--) {
    node u = pq.top(); pq.pop();
    ans += u.delta;
    int x = u.x, y = u.y;
    if (a[x] > y)
      pq.push({x, y + 1, fuck(a[x], y + 1) - fuck(a[x], y)});
  } 
  printf("%lld\n", ans);
  return 0; 
}