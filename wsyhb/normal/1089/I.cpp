#include<bits/stdc++.h>
using namespace std;
const int max_n=400+5;
int fac[max_n],I[max_n],B[max_n][max_n],A[max_n];
int main()
{
	int t,mod;
	scanf("%d%d",&t,&mod);
	const int R=400;
	fac[0]=1;
	for(int i=1;i<=R;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	for(int n=1;n<=R;++n)
	{
		int res=fac[n];
		for(int k=1;k<=n-1;++k)
			res=(res-1ll*I[k]*fac[n-k])%mod;
		res+=res<0?mod:0;
		I[n]=res;
	}
	B[0][0]=1;
	for(int k=1;k<=R;++k)
		for(int n=k;n<=R;++n)
		{
			int res=0;
			for(int t=1;t<=n;++t)
				res=(res+1ll*B[k-1][n-t]*fac[t])%mod;
			B[k][n]=res;
		}
	A[1]=1,A[2]=2;
	for(int n=3;n<=R;++n)
	{
		int res=fac[n];
		for(int k=1;k<=n-1;++k)
			res=(res-2ll*I[k]*fac[n-k])%mod;
		for(int k=3;k<=n-1;++k)
			res=(res-1ll*B[k][n]*A[k])%mod;
		res+=res<0?mod:0;
		A[n]=res;
	}
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",A[n]);
	}
	return 0;
}