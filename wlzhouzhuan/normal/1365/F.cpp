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

const int N = 505;
int a[N], b[N], n;

void solve() {
  n = read();
  for (rint i = 1; i <= n; i++) a[i] = read();
  for (rint i = 1; i <= n; i++) b[i] = read();
  if (n & 1) {
    if (a[n + 1 >> 1] != b[n + 1 >> 1]) {
      puts("No");
      return ;
    }
  }
  multiset <pii> s1, s2;
  for (rint i = 1, j = n; i < j; i++, j--) {
    if (a[i] > a[j]) swap(a[i], a[j]);
    if (b[i] > b[j]) swap(b[i], b[j]);
    s1.insert(make_pair(a[i], a[j]));
    s2.insert(make_pair(b[i], b[j]));
  }
  if (s1 != s2) {
    puts("No"); 
  } else {
    puts("Yes");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}