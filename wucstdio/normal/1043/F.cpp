#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+9;
int n,prime[300005],num,mind[300005],cnt[300005];
bool flag[300005];
ll f[300005],fact[300005],inv[300005],g[300005];
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
ll C(int n,int m)
{
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	n=300000;
	fact[0]=1;
	for(int i=1;i<=n;i++)
	  fact[i]=fact[i-1]*i%MOD;
	inv[n]=quick_pow(fact[n],MOD-2);
	for(int i=n;i>=1;i--)
	  inv[i-1]=inv[i]*i%MOD;
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			mind[i]=i;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[prime[j]*i]=1;
			mind[prime[j]*i]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	scanf("%d",&n);
	int d=0;
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		d=__gcd(d,v);
		for(int j=1;j*j<=v;j++)
		{
			if(v%j==0)
			{
				cnt[j]++;
				if(v!=j*j)cnt[v/j]++;
			}
		}
	}
//	for(int i=1;i<=15;i++)
//	  printf("%d ",cnt[i]);
//	printf("\n");
	if(d!=1)
	{
		printf("-1\n");
		return 0;
	}
	n=300000;
	for(int o=1;o<=10;o++)
	{
		for(int i=1;i<=n;i++)f[i]=C(cnt[i],o);
		for(int i=n;i>=1;i--)
		{
			for(int j=i<<1;j<=n;j+=i)
			  f[i]-=f[j];
			f[i]%=MOD;
			if(f[i]<0)f[i]+=MOD;
		}
		if(f[1])
		{
			printf("%d\n",o);
			return 0;
		}
	}
	return 0;
}