#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int A[N], n, m, a, b, G[N];

int gcd(int x, int y) {
  return (!y) ? x : gcd(y, x % y);
}

int L[N], R[N], dpL[N], dpR[N];

int pr[N], cnt;
bitset <N> B;

void prework(int n) {
  for(int i = 1; i <= n; ++ i) B[i] = 1;
  B[1] = 0;
  for(int i = 2; i <= n; ++ i) {
	if(B[i]) pr[++ cnt] = i;
	for(int j = i * 2; j <= n; j += i) B[j] = 0;
  }
}

vector <int> D;

void doit(int x) {
  for(int i = 1; i <= cnt; ++ i) {
	if(x % pr[i] == 0) {
	  D.push_back(pr[i]);
	  while(x % pr[i] == 0) x /= pr[i];
	}
  }
  if(x != 1) D.push_back(x);
}

int solve(int x) {
  for(int i = 1; i <= n; ++ i) dpL[i] = dpR[i] = 1e18;
  dpL[0] = dpR[n + 1] = 0;
  for(int i = 1; i <= n; ++ i) {
	if((A[i] + 1) % x == 0) dpL[i] = min(dpL[i - 1] + b, dpL[i]);
	if((A[i]) % x == 0) dpL[i] = min(dpL[i - 1], dpL[i]);
	if((A[i] - 1) % x == 0) dpL[i] = min(dpL[i - 1] + b, dpL[i]);
  }
  
  for(int i = n; i >= 1; -- i) {
	if((A[i] + 1) % x == 0) dpR[i] = min(dpR[i + 1] + b, dpR[i]);
	if((A[i]) % x == 0) dpR[i] = min(dpR[i + 1], dpR[i]);
	if((A[i] - 1) % x == 0) dpR[i] = min(dpR[i + 1] + b, dpR[i]);
  }

  dpL[0] -= a;
  
  int res = 1e18;

  for(int i = 1; i <= n + 1; ++ i) {
	dpL[i] -= (i + 1) * a;
	dpL[i] = min(dpL[i], dpL[i - 1]);
	res = min(res, dpR[i] + dpL[i - 1] + i * a); 
  }
  return res;
}

main() {
  prework(1e6);
  scanf("%lld", &n);
  cin >> a >> b;
  for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
  doit(A[1]);
  doit(A[1] + 1);
  doit(A[1] - 1);
  doit(A[n]);
  doit(A[n] + 1);
  doit(A[n] - 1);
  sort(D.begin(), D.begin());
  D.erase(unique(D.begin(), D.end()), D.end());
  int ans = 1e18;
  for(int i = 0; i < (int)D.size(); ++ i) {
	ans = min(ans, solve(D[i]));
  }
  cout << ans << endl;
}