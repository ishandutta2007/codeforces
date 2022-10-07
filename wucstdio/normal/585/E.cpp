#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,a[500005],c[10000005],st[15],top,mu[10000005],prime[1000005],num;
ll pw[500005];
bool flag[10000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	for(int i=1;i<=10000000;i++)
	  for(int j=2*i;j<=10000000;j+=i)
	    c[i]+=c[j];
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%MOD;
	ll sum=pw[c[1]]-1;
	mu[1]=1;
	for(int i=2;i<=10000000;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=num&&prime[j]*i<=10000000;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
		}
		sum+=mu[i]*(pw[c[i]]-1);
	}
	sum%=MOD;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int v=a[i];
		top=0;
		for(int j=2;j*j<=v;j++)
		{
			if(v%j==0)
			{
				st[++top]=j;
				while(v%j==0)v/=j;
			}
		}
		if(v!=1)st[++top]=v;
		for(int s=0;s<(1<<top);s++)
		{
			int d=1;
			bool flag=1;
			for(int j=1;j<=top;j++)
			  if((1<<(j-1))&s)
			    d=d*st[j],flag^=1;
			if(flag)ans+=pw[c[d]-1]-1;
			else ans-=pw[c[d]-1]-1;
		}
		ans-=sum;
	}
	for(int j=1;j<=10000000;j++)
	{
		ans+=mu[j]*(pw[c[j]]-1)*c[j]%MOD;
		ans-=mu[j]*(pw[c[j]-1]-1)*c[j]%MOD;
	}
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}