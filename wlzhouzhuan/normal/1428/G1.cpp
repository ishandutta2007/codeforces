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

const int N = 1000005;
long long f[N], g[N];
int k, q, mul = 1;

void ckmax(ll &a, ll b) {
  if (a < b) a = b;
}

void work() {
  int tmp = k, t = 1, x;
  x = read();
  mset(g, 192);
  for (int v = 0; v < 10; v++) {
    long long cost = 1ll * mul * v;
    long long w = v % 3 == 0 ? 1ll * (v / 3) * x : 0;
    for (int i = 0; i < N - cost; i++) {
      ckmax(g[i + cost], f[i] + w);
    }
  }
  //cerr<<"finished!\n";
  memcpy(f, g, sizeof(g));
  while (tmp > t) {
    //cerr<<"tmp="<<tmp<<'\n';
    tmp -= t;
    long long cost = 1ll * mul * t;
    cost *= 3;
    long long w = 1ll * x * t;
    if (cost < N) {
      for (int i = N - 1; i >= cost; i--) {
        ckmax(f[i], f[i - cost] + w);
      }
    }
    t <<= 1;
  }
  long long cost = 1ll * mul * tmp;
  cost *= 3;
  long long w = 1ll * x * tmp;
  if (cost < N) {
    for (int i = N - 1; i >= cost; i--) {
      ckmax(f[i], f[i - cost] + w);
    }
  }
  mul *= 10;
}
int main() {
  k = (read() - 1) * 3;  
  mset(f, 192), f[0] = 0;
  for(int i = 1; i <= 6; i++) work();
  q = read();
  while (q--) {
    int x = read();
    printf("%lld\n", f[x]);
  }
  return 0;
}