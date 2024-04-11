%:pragma GCC optimize(2)
%:pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 5;
const int N = M;

typedef long long LL;

int n, m, A[N], who[N];
LL v[N], ans[N];

main() {
  cin >> n >> m;
  //n = 100, m = 1e5;
  for(int i = 1; i <= n; ++ i) scanf("%lld", &v[i]);
  for(int s = 2; s <= (m << 1); ++ s) {
    for(int j = 1; j <= n; ++ j) A[j] = v[j] % s;
    sort(A + 1, A + n + 1);
    A[n + 1] = s - 1;
    int cur = 0;
    for(int i = n + 1; i >= 1; -- i, cur ^= 1) {
      int l = max(A[i - 1] + 1, A[n - cur] / 2 + 1),
	r = min(A[i], m);
      int mn = max(s - r, l);
      int mx = min(s - l, r);
      if(mn <= mx) ans[cur] += mx - mn + 1;
    }
  }
  LL All = 1LL * m * m;
  LL ea = (All - ans[0] - ans[1]) >> 1;
  cout << ea <<" " << ea <<" " << ans[1] <<" " << ans[0] << endl;
}