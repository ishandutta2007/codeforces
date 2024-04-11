#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7,Maxn=10005;
long long dp[Maxn],A[60][60],inv[60];
vector <int> Ve[Maxn];
long long fast_pow(long long x,long long y)
{
	long long ans=1,now=x;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
long long ans=1,n;
int k,fac[Maxn],ct[Maxn],cnt;
void init(void)
{
	for(int i=1;i<=50;i++)
		inv[i]=fast_pow(i,p-2);
}
long long work(int q)
{
	memset(dp,0,sizeof(dp));
	dp[q]=1;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=q;j++)
		{
			long long tmp=0;
			for(int t=j;t<=q;t++)
				tmp=(tmp+dp[t]*inv[t+1]%p)%p;
			dp[j]=tmp;
		}
	for(int i=0;i<=q;i++)
		A[q][i]=dp[i];
}
int main()
{
//	n=6,k=2;
	init();
	scanf("%lld%d",&n,&k);
	int maxi=sqrt(n);
	for(int i=2;i<=maxi;i++)
	{
		if(n%i==0) fac[++cnt]=i;
		while(n%i==0) n/=i,ct[cnt]++;
	}
	if(n!=1) fac[++cnt]=n%p,ct[cnt]++;
	for(int i=1;i<=cnt;i++)
	{
		long long tmp=0;
		for(int j=0;j<=ct[i];j++)
		{
			if(!A[ct[i]][0]) work(ct[i]);
			tmp=(tmp+A[ct[i]][j]%p*fast_pow(fac[i]%p,j)%p)%p;
		}
		ans=(ans*tmp)%p;
	}
	printf("%lld",ans);
	return 0;
}