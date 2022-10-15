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

const int N = 1000002;
vector <int> pr;
int vis[N];
void pre(int n) {
  vis[0] = vis[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.pb(i);
    for (auto v: pr) {
      if (i * v > n) break;
      vis[v * i] = 1;
      if (i % v == 0) break;
    }
  } 
}
int rev(int x) {
  int y = 0;
  while (x > 0) {
    y = 10 * y + x % 10;
    x /= 10;
  } 
  return y;
}
int n;
int main() {
  pre(1e6);
  scanf("%d", &n);
  for (rint i = 2; ; i++) {
    if (!vis[i] && !vis[rev(i)] && rev(i) != i) {
      n--;
      if (n == 0) {
        printf("%d\n", i);
        exit(0);
      } 
    }
  }
}