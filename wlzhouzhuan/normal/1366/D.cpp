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

const int N = 10000005;

bitset <N> vis;
vector <int> prime;
int minp[N];
void pre(int n) {
  for (rint i = 2; i <= n; i++) {
    if (!vis[i]) prime.pb(i), minp[i] = i;
    for (auto v: prime) {
      if (v * i > n) break;
      vis[i * v] = 1;
      minp[i * v] = v;
      if (i % v == 0) break;
    }
  }
}

pii a[N];
int n;

int main() {
  pre(1e7);
  n = read();
  for (rint i = 1; i <= n; i++) {
    int x = read(), tmp = x;
    vector <int> inz;
    while (x > 1) {
      inz.pb(minp[x]);
      x /= minp[x];
    }
    int sz = inz.size();
    if (inz[0] == inz[sz - 1]) {
      a[i] = make_pair(-1, -1);
      continue;
    } 
    int t = 1;
    for (auto v: inz) {
      if (v == inz[0]) {
        t *= v;
      }
    }
    a[i] = make_pair(t, tmp / t);
  }
  for (rint i = 1; i <= n; i++) printf("%d ", a[i].fir);
  puts("");
  for (rint i = 1; i <= n; i++) printf("%d ", a[i].sec);
  puts("");
  return 0;
}