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

int minp[5555];
int n, m;

int ask(int x, int y, int i1, int j1, int i2, int j2) {
  printf("? %d %d %d %d %d %d\n", x, y, i1, j1, i2, j2);
  fflush(stdout);
  int t; scanf("%d", &t);
  return t;
}
int main() {
  for (int i = 2; i <= 1000; i++) {
    for (int j = i; j <= 1000; j += i) {
      if (!minp[j]) minp[j] = i;
    }
  }
  scanf("%d%d", &n, &m);
  int nn = n, mm = m;
  int ansn = 1, ansm = 1;
  for (int i = n; i > 1; i /= minp[i]) {
    if (minp[i] == 2) {
      int len = nn / minp[i];
      if (ask(len, m, 1, 1, len + 1, 1)) {
        nn /= minp[i];
      }
    } else {
      int len = nn / minp[i];
      int mid = minp[i] / 2 * len;
      if (ask(mid, m, 1, 1, mid + len + 1, 1) && ask(mid, m, 1, 1, mid + 1, 1)) {
        nn /= minp[i];
      }
    }
  }
  for (int i = m; i > 1; i /= minp[i]) {
    if (minp[i] == 2) {
      int len = mm / minp[i];
      if (ask(n, len, 1, 1, 1, len + 1)) {
        mm /= minp[i];
      }
    } else {
      int len = mm / minp[i];
      int mid = minp[i] / 2 * len;
      if (ask(n, mid, 1, 1, 1, mid + len + 1) && ask(n, mid, 1, 1, 1, mid + 1)) {
        mm /= minp[i];
      }
    }
  }
  int d1 = 0, d2 = 0;
//  cerrr << nn << ' ' << mm << '\n';
  nn = n / nn, mm = m / mm;
  for (int i = 1; i <= nn; i++) if (nn % i == 0) d1++;
  for (int i = 1; i <= mm; i++) if (mm % i == 0) d2++;
  printf("! %d\n", d1 * d2), fflush(stdout);
  return 0;
}