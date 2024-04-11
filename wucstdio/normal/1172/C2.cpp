#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m,a[300005],w[300005],s1,s2;
ll f[3005][3005];
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
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		if(a[i])s1+=w[i];
		else s2+=w[i];
	}
	f[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j)f[i][j]+=f[i-1][j-1]*(s1+j-1)%MOD*quick_pow(s1+j-1+s2-(i-j),MOD-2)%MOD;
			if(j!=i)f[i][j]+=f[i-1][j]*(s2-(i-1-j))%MOD*quick_pow(s1+j+s2-(i-1-j),MOD-2)%MOD;
		}
	}
	ll res1=0,res2=0;
	for(int i=0;i<=m;i++)
	{
		res1=(res1+f[m][i]*(s1+i))%MOD;
		res2=(res2+f[m][i]*(s2-(m-i)))%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)printf("%I64d\n",(w[i]%MOD*quick_pow(s1,MOD-2)%MOD*res1%MOD+MOD)%MOD);
		else
		{
			printf("%I64d\n",(w[i]%MOD*quick_pow(s2,MOD-2)%MOD*res2%MOD+MOD)%MOD);
		}
	}
	return 0;
}