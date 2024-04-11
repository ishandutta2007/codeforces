#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,m,now,num,ans=1,inv[1005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	x%=MOD;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
ll solve()
{
	if(num==0)return 1;
	ll p[105][10005];
	for(int i=0;i<num;i++)
	  p[i][0]=0;
	p[num][0]=1;
	for(int i=1;i<=m;i++)
	for(int j=0;j<=num;j++)
	{
		p[j][i]=0;
		for(int k=j;k<=num;k++)
		  p[j][i]+=p[k][i-1]*inv[k+1]%MOD;
		p[j][i]%=MOD;
	}
	ll ans=0;
	for(int i=0;i<=num;i++)
	  ans+=quick_pow(now,i)*p[i][m]%MOD;
	return ans%MOD;
}
int main()
{
	for(int i=1;i<=1000;i++)
	  inv[i]=quick_pow(i,MOD-2);
	scanf("%I64d%I64d",&n,&m);
	for(ll i=2;i*i<=n;i++)
	{
		now=i;
		num=0;
		if(n%i)continue;
		while(n%i==0)
		{
			n/=i;
			num++;
		}
		ans=ans*solve()%MOD;
	}
	if(n!=1)
	{
		now=n;
		num=1;
		ans=ans*solve()%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}