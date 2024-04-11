#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, l, r, k, L, R;

LL ans = -1;

void solve(LL t) {
  if(t == 0) {
    LL a = L, b = k - R;
    if(b < 0 || b > R) return;
    ans = max(ans, a + min(b + 1, R));
  }
  if(t <= 0) return;
  LL All = k;
  All -= L * t + R * (t + 1);
  if(All < 0) return;
  LL a, b;
  // a [0, L] b [0, R]
  //exgcd(t, t + 1, a, b);
  a = -All;
  b = All;
  LL now = (All) / (t + 1);
  a = a + now * (t + 1);
  b = b - now * t;
  if(a < 0) a += t + 1, b -= t;
  if(b < 0) return;
  if(a > L) return;
  now = min(b / t, (L - a) / (t + 1));
  a += now * (t + 1);
  b -= now * t;
  if(b > R) return;
  ans = max(ans, a + b);
}

void solve2(LL t) {
  if(t <= 0) return;
  if(!R) return;
  LL All = k;
  All -= L * t + (R + 1) * (t + 1);
  if(All < 0) return;
  LL a, b;
  // a [0, L] b [0, R - 1]
  //exgcd(t, t + 1, a, b);
  a = -All;
  b = All;
  LL now = (All) / (t + 1);
  a = a + now * (t + 1);
  b = b - now * t;
  if(a < 0) a += t + 1, b -= t;
  if(b < 0) return;
  if(a > L) return;
  now = min(b / t, (L - a) / (t + 1));
  a += now * (t + 1);
  b -= now * t;
  if(b >= R) return;
  ans = max(ans, a + b + 1);
}

int main() {
  cin >> n >> l >> r >> k;
  L = n - (r - l + 1 + n) % n;
  R = (r - l + 1 + n) % n;
  LL t, next;
  if(!R) swap(L, R);
  //cerr << L <<" " << R << endl;
  solve(0);
  //cerr << "HERE" << endl;
  for(LL i = n; i <= n * 2; i = next + 1) {
    LL t = k / i;
    next = (!t) ? 1e18 : (k / t);
    solve(t - 1);
    solve(t);
    solve(t + 1);
    //cerr << i <<" " << next << endl;
  }
  ++ k;
  for(LL i = n; i <= n * 2; i = next + 1) {
    LL t = k / i;
    next = (!t) ? 1e18 : (k / t);
    solve2(t - 1);
    solve2(t);
    solve2(t + 1);
  }
  cout << ans << endl;
}