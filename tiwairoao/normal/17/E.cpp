#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD = 51123987;
const int MAXN = 4*int(1E6);
int a[MAXN + 5], p[MAXN + 5];
int f[MAXN + 5], g[MAXN + 5];
char s[MAXN + 5];
int main() {
	int N, mxp = 0, tot = 0, ans = 0;
	scanf("%d%s", &N, s);
	for(int i=0;i<N;i++)
		a[i<<1|1] = s[i];
	p[0] = 1;
	for(int i=1;i<=2*N;i++) {
		if( mxp + p[mxp] <= i ) p[i] = 1;
		else p[i] = min(p[2*mxp-i], mxp+p[mxp]-i);
		while( i-p[i] >= 0 && i+p[i] <= 2*N && a[i-p[i]] == a[i+p[i]] )
			p[i]++;
		if( i + p[i] > mxp + p[mxp] )
			mxp = i;
		ans = (ans + 1LL*(p[i]/2)*(p[i]/2-1)/2%MOD)%MOD;
		ans = (ans + 1LL*p[i]/2*tot%MOD)%MOD;
		tot = (tot + p[i]/2)%MOD;
	}
	for(int i=0;i<=2*N;i++) {
		f[i-p[i]+1]++;
		if( i != 2*N ) f[i+1]--;
		g[i+p[i]-1]++;
		if( i != 0 ) g[i-1]--;
	}
	for(int i=1;i<2*N;i++)
		f[i] = (f[i] + f[i-1]) % MOD;
	for(int i=2*N-1;i>0;i--)
		g[i] = (g[i] + g[i+1]) % MOD;
	int sum = 0;
	for(int i=1;i+2<2*N;i+=2) {
		sum = (sum + g[i])%MOD;
		ans = (ans - 1LL*sum*f[i+2]%MOD)%MOD;
	}
	printf("%d\n", (ans%MOD + MOD)%MOD);
}