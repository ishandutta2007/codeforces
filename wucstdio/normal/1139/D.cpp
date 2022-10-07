#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll prime[100005],num,mu[100005];
ll f[100005],g[100005];
int n;
bool flag[100005];
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
void pre(int n)
{
	flag[1]=1;
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
		}
	}
}
int main()
{
	scanf("%d",&n);
	pre(n);
	f[1]=1;
	for(int i=1;i<=n;i++)
	  g[i]+=mu[i];
	ll inv=quick_pow(n,MOD-2);
	ll ans=1;
	for(int i=2;i<=n;i++)
	{
		for(int t=1;t*t<=i;t++)
		{
			if(i%t)continue;
			f[i]+=g[t]*(n/t)%MOD;
			if(i!=t*t)f[i]+=g[i/t]*(n/(i/t))%MOD;
		}
		f[i]%=MOD;
		f[i]=f[i]*inv%MOD;
		f[i]++;
		f[i]=f[i]*quick_pow(1-inv*(n/i)%MOD+MOD,MOD-2)%MOD;
		ans+=f[i];
		for(int j=i;j<=n;j+=i)
			g[j]=(g[j]+f[i]*mu[j/i])%MOD;
	}
	ans%=MOD;
	ans=ans*inv%MOD;
	if(ans<0)ans+=MOD;
	printf("%I64d\n",ans);
	return 0;
}