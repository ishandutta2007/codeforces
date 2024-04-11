// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#define p 998244353
using namespace std;
long long fact[300001], invf[300001], dp[300001];
long long quickpow(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
long long c(int n, int m) {
	if(n < m)
		return 0;
	return fact[n] * invf[m] % p * invf[n-m] % p;
}
int cnt[300001], ton[300001];
int main() {
	int n=0,m,i,j,k;
	scanf("%d",&m);
	for (i = 1; i <= m; i ++) {
		int x;
		scanf("%d",&x);
		if(x > n)
			n = x;
		++ cnt[x];
	}
	fact[0] = 1;
	for (i = 0; ++ i <= n; )
		for (j = i; j <= n; j += i)
			ton[i] += cnt[j];
	for (i = 0; ++ i <= m; )
		fact[i] = (fact[i - 1] * i) % p;
	invf[m] = quickpow(fact[m],p - 2);
	for (i = m; ~ -- i; )
		invf[i] = (invf[i + 1] * (i + 1)) % p;
	for (k = 0; ++ k <= 7; ) {
		if(k > m)
			break;
		for (i = n + 1; -- i; ) {
			dp[i] = c(ton[i],k);
			for (j = i << 1; j <= n; j += i)
				dp[i] = (dp[i] - dp[j] + p) % p;
		}
		if (dp[1]) {
			printf("%d\n",k);
			return 0;
		}
	}
	puts("-1");
	return 0;
}