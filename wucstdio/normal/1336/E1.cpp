#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m;
ll b[45],res[45],f[45][1<<15];
ll a[45];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
void ins(ll v)
{
	for(int i=m-1;i>=0;i--)
	{
		if(!(v&(1ll<<i)))continue;
		if(b[i])v^=b[i];
		else
		{
			b[i]=v;
			return;
		}
	}
}
int calc(ll x)
{
	int ans=0;
	while(x)
	{
		ans+=int(x&1);
		x>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		ins(x);
	}
	for(int i=0;i<m;i++)
	{
		if(!b[i])continue;
		for(int j=i+1;j<m;j++)
			if((1ll<<i)&b[j])b[j]^=b[i];
	}
	int num=0;
	int k=0;
	for(int i=m-1;i>=0;i--)
	{
		if(!b[i])continue;
		int kk=0;
		for(int j=0;j<m;j++)
		{
			if(!b[j])
			{
				if((1ll<<j)&b[i])a[num]|=1ll<<kk;
				kk++;
			}
		}
		k=max(k,kk);
//		printf("%lld ",a[num]);
		num++;
	}
//	printf("\n");
//	for(int i=0;i<m;i++)printf("%lld ",b[i]);
//	printf("\n");
	if(num<=20)
	{
		for(int i=0;i<(1ll<<num);i++)
		{
			int cnt=0;
			ll v=0;
			for(int j=0;j<num;j++)
			{
				if((1<<j)&i)
				{
					cnt++;
					v^=a[j];
				}
			}
			res[cnt+calc(v)]++;
		}
		for(int i=0;i<=m;i++)printf("%lld ",res[i]*quick_pow(2,n-num)%MOD);
		printf("\n");
		return 0;
	}
	f[0][0]=1;
	for(int i=0;i<num;i++)
	{
		for(int j=i;j>=0;j--)
		{
			for(int s=0;s<(1ll<<k);s++)
			{
				f[j+1][s^a[i]]+=f[j][s];
				f[j+1][s^a[i]]%=MOD;
			}
		}
	}
	for(int i=0;i<=num;i++)
	{
		for(int s=0;s<(1ll<<k);s++)
		  res[calc(s)+i]=(res[calc(s)+i]+f[i][s])%MOD;
	}
	for(int i=0;i<=m;i++)printf("%lld ",res[i]*quick_pow(2,n-num)%MOD);
	printf("\n");
	return 0;
}