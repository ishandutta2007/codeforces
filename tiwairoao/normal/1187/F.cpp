#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
const int MOD = int(1E9) + 7;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int P[MAXN + 5], S[MAXN + 5];
int l[MAXN + 5], r[MAXN + 5], n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &l[i]);
	for(int i=1;i<=n;i++) scanf("%d", &r[i]);
	for(int i=1;i<n;i++) {
		int len = max(0, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1);
		int tmp = 1LL*pow_mod(r[i] - l[i] + 1, MOD - 2)*pow_mod(r[i + 1] - l[i + 1] + 1, MOD - 2)%MOD;
		P[i] = (1 + MOD - 1LL*tmp*len%MOD)%MOD;
	}
	for(int i=1;i<n;i++) S[i] = (P[i] + S[i-1])%MOD;
	int ans = (3LL*S[n - 1]%MOD + 1)%MOD;
	for(int i=1;i+2<n;i++)
		ans = (ans + 2LL*(S[n - 1] + MOD - S[i + 1])%MOD*P[i]%MOD)%MOD;
	for(int i=1;i+1<n;i++) {
		int len = max(0, min(r[i], min(r[i + 1], r[i + 2])) - max(l[i], max(l[i + 1], l[i + 2])) + 1);
		int tmp = 1LL*pow_mod(r[i] - l[i] + 1, MOD - 2)%MOD*pow_mod(r[i + 1] - l[i + 1] + 1, MOD - 2)%MOD*pow_mod(r[i + 2] - l[i + 2] + 1, MOD - 2)%MOD;
		int del = 1;
		del = ((del + P[i])%MOD + MOD - 1)%MOD;
		del = ((del + P[i + 1])%MOD + MOD - 1)%MOD;
		del = (del + 1LL*tmp*len%MOD)%MOD;
		ans = (ans + 2LL*del%MOD)%MOD;
	}
	printf("%d\n", ans);
}