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
const int inf = 1e9;

int k[N], al[N], ar[N], bl[N], br[N], cl[N], cr[N], dl[N], dr[N];
int n, m;

int main() {
  n = read(), m = read();
  rep(i, 1, n) {
    k[i] = read();
    al[i] = read(), bl[i] = read();
    ar[i] = read(), br[i] = read();
  }
  cl[n + 1] = 0, dl[n + 1] = m;
  cr[n + 1] = 0, dr[n + 1] = m;
  per(i, n, 1) {
    cl[i] = inf, dl[i] = 0;
    cr[i] = inf, dr[i] = 0;
    if (al[i] <= k[i] && k[i] <= bl[i]) {
      if (cl[i + 1] <= k[i] && k[i] <= dl[i + 1]) {
        cr[i] = ar[i];
        dr[i] = br[i];
      } else {
        cr[i] = max(cr[i + 1], ar[i]);
        dr[i] = min(dr[i + 1], br[i]);
      }
    }
    if (ar[i] <= k[i] && k[i] <= br[i]) {
      if (cr[i + 1] <= k[i] && k[i] <= dr[i + 1]) {
        cl[i] = al[i];
        dl[i] = bl[i];
      } else {
        cl[i] = max(cl[i + 1], al[i]);
        dl[i] = min(dl[i + 1], bl[i]);
      }
    }
  }
  if ((cl[1] <= 0 && 0 <= dl[1]) || (cr[1] <= 0 && 0 <= dr[1])) {
    puts("Yes");
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      if (al[i] <= k[i] && k[i] <= bl[i] && ar[i] <= y && y <= br[i] &&
          ((cl[i + 1] <= k[i] && k[i] <= dl[i + 1]) || (cr[i + 1] <= y && y <= dr[i + 1]))) {
        x = k[i];
        putchar('0');    
      } else {
        y = k[i];
        putchar('1');
      }
      putchar(' ');
    }
  } else {
    puts("No");
  }
  return 0;
}