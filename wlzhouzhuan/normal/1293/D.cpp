#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
  ll x; scanf("%lld", &x);
  return x;
}
const int N = 105;
ll x[N], y[N], ax, ay, bx, by;
ll xs, ys, t;
int n;
ll dist[N][N];

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) { if (x < y) x = y; }
int main() {
  x[0] = read(), y[0] = read(), ax = read(), ay = read(), bx = read(), by = read();
  xs = read(), ys = read(), t = read();
  //printf("%lld %lld\n", x[0], y[0]);
  for (n = 1; ; n++) {
    x[n] = x[n - 1] * ax + bx, y[n] = y[n - 1] * ay + by;
    //printf("x[%d] = %lld, y[%d] = %lld\n", n, x[n], n, y[n]);
    if (x[n] > 3e16 || y[n] > 3e16) break;
  }
  for (int i = 0; i <= n; i++)
    for (int j = i; j <= n; j++) 
      dist[i][j] = x[j] - x[i] + y[j] - y[i];
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ll left_t = t - (llabs(xs - x[i]) + llabs(ys - y[i]));
    //printf("left_t = %lld, %lld\n", left_t, dist[0][1]);
    if (left_t < 0) continue;
    for (int j = i; j <= n; j++) {
      if (dist[i][j] <= left_t) ckmax(ans, j - i + 1);
    }
    for (int j = 0; j <= i; j++) {
      if (dist[j][i] <= left_t) ckmax(ans, i - j + 1);
    }
  }  
  printf("%d\n", ans);
  return 0;
}

/*
9999999999999999 1 2 2 0 0
10000000000000000 1 10000000000000000
*/