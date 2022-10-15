// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll au[155], cnt;
ll t, a, b;

bool check(ll x, ll y) {
  ll tot = 0;
  for (int i = cnt; i >= 0; i--) {
    if ((double)tot * x > (double)y) return 0;
    tot = tot * x + au[i];
    if (tot > y) return 0;
  }
  return tot == y;
} 
ll get(ll a, ll b) {
  ll ret = 0;
  while (b % a == 0) ret++, b /= a;
  return b > 1 ? -1 : ret;
}
int main() {
  while (~scanf("%lld%lld%lld", &t, &a, &b)) {
    if (t == 1 && a == 1 && b == 1) {
      puts("inf");
      continue;
    }
    int ans = 0;
    if (a == b) ans++;
    if (t == 1 && a > 1) {
      long long t = get(a, b);
      if (~t && t > 1) ans++;
    }
    if (a > 1) {
      cnt = -1;
      while (b > 0) {
        au[++cnt] = b % a;
        b /= a;
      }
      if (check(t, a)) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}