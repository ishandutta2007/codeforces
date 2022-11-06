#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL MOD = 1e9+9;
char s[100010];
LL A,B;
LL N,K;

LL po(LL a,LL x)
{
	LL ret = 1;
	while(x)
	{
		if (x & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return ret;
}

LL rev(LL x)
{
	return po(x,MOD - 2);
}

LL gao(LL x)
{
	if (x < 0) x += MOD;
	return x;
}

int main()
{
	scanf("%lld%lld%lld%lld",&N,&A,&B,&K);
	scanf("%s",s);
	LL a1 = 0;
	for (int i=0;i<K;i++)
	{
		LL tmp = po(A,N-i);
		tmp = tmp * po(B,i) % MOD;
		if (s[i] == '-') tmp = MOD - tmp;
		a1 += tmp;
		a1 %= MOD;
	}
	//printf("%lld\n",a1);
	LL d = po(rev(A),K) * po(B,K) % MOD;
	//printf("%lld\n",d);
	N = (N+1) / K;
	LL ans;
	if (d == 1) ans = a1 * N % MOD;
	else ans = a1 * gao(po(d,N) - 1) % MOD * rev(gao(d - 1)) % MOD;
	printf("%lld\n",ans);
}