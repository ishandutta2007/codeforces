#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }
int binpow(int x, int p) {
	int res = 1;
	while (p) {
		if (p&1) res = mult(res, x);
		p/=2;
		x = mult(x, x);
	}
	return res;
}
int inv(int x) { return binpow(x, MOD-2); }

int n, p;
int powp[2013], pownp[2013];

int low[2013][2013]; // probability among i players lowest SCC has size j
int dp[2013]; // E[total games] with i players

int main() {
	scanf("%d", &n);
	int a,b;
	scanf("%d%d", &a, &b);
	p = mult(a, inv(b));
	powp[0] = pownp[0] = 1;
	for (int i=1;i<=n;i++) {
		powp[i] = mult(powp[i-1], p);
		pownp[i] = mult(pownp[i-1], sub(1, p));
	}

	low[0][0] = 1;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=i;j++) {
			// add
			low[i+1][j+1] = add(low[i+1][j+1], mult(low[i][j], powp[i-j]));
			// don't
			low[i+1][j] = add(low[i+1][j], mult(low[i][j], pownp[j]));
		}
	}
	for (int i=1;i<=n;i++) {
		low[i][i] = 1;
		for (int j=1;j<i;j++) {
			low[i][j] = mult(low[i][j], low[j][j]);
			low[i][i] = sub(low[i][i], low[i][j]);
		}
	}

	for (int i=1;i<=n;i++) {
		dp[i] = i*(i-1)/2;
		for (int j=1;j<i;j++) {
			int cur = add(dp[j], sub(dp[i-j], (i-j)*(i-j-1)/2));
			dp[i] = add(dp[i], mult(low[i][j], cur));
		}
		//X = aY + bX -> X = aY/(1 - b)
		dp[i] = mult(dp[i], inv(sub(1, low[i][i])));
	}
	printf("%d\n",dp[n]);
}