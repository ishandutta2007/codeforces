#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1111111;

int stk[N], tot, A[N], L[N], R[N], n, k;

const int mod = 1e9 + 7;

int calc(int x) {
  // x + (x - k) + (x - 2k)
  int now = x / k;
  int beg = x - now * k, end = x;
  int tim = now + 1;
  return (beg + end) * tim / 2 % mod;
}

main() {
  cin >> n >> k;
  -- k;
  for(int i = 1; i <= n; ++ i) {
    scanf("%lld", &A[i]);
  }
  A[0] = 1e9 + 7;
  stk[++ tot] = 0;
  for(int i = 1; i <= n; ++ i) {
    while(A[i] > A[stk[tot]]) -- tot;
    L[i] = stk[tot] + 1;
    stk[++ tot] = i;
  }
  A[n + 1] = 1e9 + 7;
  tot = 0;
  stk[++ tot] = n + 1;
  for(int i = n; i >= 1; -- i) {
    while(A[i] >= A[stk[tot]]) -- tot;
    R[i] = stk[tot] - 1;
    stk[++ tot] = i;
  }

  int ans = 0;
  
  for(int i = 1; i <= n; ++ i) {
    int l = i - L[i], r = R[i] - i;
    if(l + r < k) continue;
    int now = calc(r + l + 1) - calc(l) - calc(r);
    now %= mod;
    now = (now + mod) % mod;
    ans += (now - 1) * A[i];
    ans %= mod;
  }
  cout << ans << endl;
}