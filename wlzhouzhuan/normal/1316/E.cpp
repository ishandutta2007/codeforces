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
 
template <typename T>
void ckmax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
void ckmin(T &a, T b) {
  if (a > b) a = b;
}
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
ll f[N][128], s[N][7];
int bit[N], id[N], a[N];
int n, p, k;

/*
f[i][j]  i  j  
*/

int main() {
  scanf("%d%d%d", &n, &p, &k);
  for (rint i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [&](int x, int y) {
    return a[x] > a[y];
  });
  for (rint i = 1; i <= n; i++) {
    for (rint j = 0; j < p; j++) {
      scanf("%d", &s[i][j]);
    }
  }
  
  int all = 1 << p;
  for (rint i = 0; i < all; i++) bit[i] = bit[i >> 1] + (i & 1);
  mset(f, -0x3f), f[0][0] = 0;
  for (rint i = 1; i <= n; i++) {
    int x = id[i];
    for (rint st = 0; st < all; st++) {
      ll chose = (i - 1) - bit[st]; //  x  
      if (chose < k) { //  
        ckmax(f[i][st], f[i - 1][st] + a[x]);
      } else { //  
        ckmax(f[i][st], f[i - 1][st]); 
      }
      //  x 
      for (rint j = 0; j < p; j++) {
        if (st >> j & 1) {
          ckmax(f[i][st], f[i - 1][st ^ 1 << j] + s[x][j]);
        }
      } 
    }
  }
  printf("%lld\n", f[n][all - 1]);
  return 0;
}