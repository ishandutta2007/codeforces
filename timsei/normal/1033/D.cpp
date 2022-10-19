#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e6 + 5;

#define int long long

int n, cnt, pr[N];
LL A[N];

map < LL, int > frq, o2;
bool isp[N];

const int mod = 998244353;

LL gcd(LL x, LL y) {
  return (!y) ? x : gcd(y, x % y);
}

void calc(LL x) {
  LL d2 = sqrt(x) + 1e-3;
  LL d3 = cbrt(x) + 1e-3;
  LL d4 = sqrt(d2) + 1e-3;
  if(d4 * d4 * d4 * d4 == x) {
    frq[d4] += 4;
    return;
  }
  if(d2 * d2 == x) {
    frq[d2] += 2;
    return;
  }
  if(d3 * d3 * d3 == x) {
    frq[d3] += 3;
    return;
  }
  for(int i = 1; i <= n; ++ i) {
    if(gcd(A[i], x) != x && gcd(A[i], x) != 1) {
      ++ frq[gcd(A[i], x)];
      ++ frq[x / gcd(A[i], x)];
      return;
    }
  }
  ++ o2[x];
}

main() {
  //cerr << cnt << endl;
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    cin >> A[i];
  }
  for(int i = 1; i <= n; ++ i) calc(A[i]);
  int ans = 1;
  for(map < LL, int > :: iterator it = frq.begin(); it != frq.end(); ++ it) {
    ans = 1LL * ans * (it -> second + 1) % mod;
  }
  for(map < LL, int > :: iterator it = o2.begin(); it != o2.end(); ++ it) {
    ans = 1LL * ans * (it -> second + 1) % mod;
    ans = 1LL * ans * (it -> second + 1) % mod;
  }
  cout << ans << endl;
}