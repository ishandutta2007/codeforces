#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

typedef long long LL;

int n, Bit[N], S[2];
LL A[N];

int bc(LL x) {
  int res = 0;
  for(; x; x >>= 1) {
    if(x & 1) ++ res;
  }
  return res;
}

main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i)
    scanf("%lld", &A[i]), Bit[i] = bc(A[i]);
  S[0] = 1;
  int now = 0;
  LL ans = 0;
  for(int i = 1; i <= n; ++ i) {
    now = (now + Bit[i]) & 1;
    ans += S[now];
    ++ S[now];
  }
  for(int i = 1; i <= n; ++ i) {
    int now = 0, MAX = 0;
    for(int j = i; j <= min(n, i + 64); ++ j) {
      MAX = max(MAX, Bit[j]);
      now += Bit[j];
      if(now & 1) continue;
      else {
	if(MAX * 2 > now) -- ans;
      }
    }
  }
  cout << ans << endl;
}