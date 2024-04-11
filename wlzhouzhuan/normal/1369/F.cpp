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
int win[N], lose[N], t;

bool Win(ll s, ll e) {
  if (e & 1) {
    if (s & 1) return 0;
    else return 1;
  } else {
    if (e / 2 < s) {
      if (s & 1) return 1;
      else return 0;
    } else if (e / 4 < s) {
      return 1;
    } else {
      return Win(s, e / 4);
    }
  }
}
bool Lose(ll s, ll e) {
  if (2ll * s > e) return 1;
  else return Win(s, e / 2);
}

int main() {
  scanf("%d", &t);
  for (rint i = 1; i <= t; i++) {
    ll s, e;
    scanf("%lld%lld", &s, &e);
    win[i] = Win(s, e);
    lose[i] = Lose(s, e);
  }
  int wi = 0, los = 1;
  for (rint i = 1; i <= t; i++) {
    if (wi == los) { // 
      break; 
    }
    if (wi) { // 
      win[i] ^= 1;
      lose[i] ^= 1; 
    }
    wi = win[i];
    los = lose[i]; 
  } 
  printf("%d %d\n", wi, los);
  return 0;
}