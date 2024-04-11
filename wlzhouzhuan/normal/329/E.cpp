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

const int N = 100005;

struct node {
  int x, y;
} a[N];
ll ans;
int tmpx[N], tmpy[N];
int n;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read(), a[i].y = read();
    tmpx[i] = a[i].x, tmpy[i] = a[i].y;
  }
  //  
  if (n == 1) return puts("0"), 0;
  if (n == 2) return printf("%lld\n", 2ll * (abs(a[1].x - a[2].x) + abs(a[1].y - a[2].y))), 0;
  sort(tmpx + 1, tmpx + n + 1);
  sort(tmpy + 1, tmpy + n + 1);
  int m = n + 1 >> 1, dx, dy; //  
  dx = tmpx[m + 1] - tmpx[m], dy = tmpy[m + 1] - tmpy[m];
  if (n % 2 == 1) {
    dx = min(dx, tmpx[m] - tmpx[m - 1]);
    dy = min(dy, tmpy[m] - tmpy[m - 1]);
  }
  dx = min(dx, dy);
  
  int o = 0, s[2][2] = {0};
//  printf("tmpx = %d, tmpy = %d\n", tmpx[m], tmpy[m]);
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i].x - tmpx[m]) + abs(a[i].y - tmpy[m]);
    s[a[i].x <= tmpx[m]][a[i].y <= tmpy[m]]++; // 
    if (a[i].x == tmpx[m] && a[i].y == tmpy[m]) o = 1; //  = 1 
  }
  if ((n % 2 == 0 || o) && s[0][0] && s[0][1] && s[1][0] && s[1][1]) ans -= dx;
  printf("%lld\n", 2ll * ans);
  return 0;
}