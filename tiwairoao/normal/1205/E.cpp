#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int MOD = int(1E9) + 7;
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int n, m, k, ans;
void update(int d, int s, int p) {
	ans = (ans + 1LL*p*pow_mod(k, MOD - 1 + max(s - n, d) - n)%MOD)%MOD;
}
vector<int>dv[2*MAXN + 5];
void init() {
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i)
			dv[j].push_back(i);
}
int f[2*MAXN + 5];
int main() {
	scanf("%d%d", &n, &k), m = 2*(n - 1);
	init();
	for(int s=1;s<=m;s++) {
		int l = max(1, s - (n - 1)), r = min(n - 1, s - 1);
		for(int j=dv[s].size()-1;j>=0;j--) {
			int d = dv[s][j], p = s / d;
			f[d] = r / d - (l - 1) / d;
			for(int k=1;k<dv[p].size();k++)
				f[d] = (f[d] + MOD - f[d*dv[p][k]])%MOD;
			update(d, s, f[d]);
		}
	}
/*
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-1;j++)
			update(gcd(i, j), i + j, 1);
*/
	printf("%d\n", ans);
}