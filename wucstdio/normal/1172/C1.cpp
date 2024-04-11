#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
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
int n,m,a[55],w[55];
ll f[55][55][55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	int s=0,s2=0;
	for(int i=1;i<=n;i++)s+=w[i];
	for(int i=1;i<=n;i++)
	  if(a[i]==0)s2+=w[i];
	for(int x=1;x<=n;x++)
	{
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		for(int i=1;i<=m;i++)
		for(int j=0;j<=i;j++)
		for(int k=0;k<=i;k++)
		{
			if(a[x]==1)
			{
				if(j+k>i)break;
				if(j)f[i][j][k]=f[i-1][j-1][k]*(w[x]+j-1)%MOD*quick_pow(s-k+(i-1-k),MOD-2)%MOD;
				if(k)f[i][j][k]+=f[i-1][j][k-1]*(s2-(k-1))%MOD*quick_pow(s-(k-1)+(i-k),MOD-2)%MOD;
				f[i][j][k]+=f[i-1][j][k]*(s-k+(i-1-k)-(s2-k)-(w[x]+j))%MOD*quick_pow(s-k+(i-1-k),MOD-2)%MOD;
			}
			else
			{
				if(k<j)continue;
				if(j)f[i][j][k]=f[i-1][j-1][k-1]*(w[x]-(j-1))%MOD*quick_pow(s-(k-1)+(i-k),MOD-2)%MOD;
				if(k)f[i][j][k]+=f[i-1][j][k-1]*(s2-(k-1)-(w[x]-j))%MOD*quick_pow(s-(k-1)+(i-k),MOD-2)%MOD;
				f[i][j][k]+=f[i-1][j][k]*(s-k+(i-1-k)-(s2-k))%MOD*quick_pow(s-k+(i-1-k),MOD-2)%MOD;
			}
		}
		ll ans=0;
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=m;j++)
			  ans+=f[m][i][j]*(a[x]?w[x]+i:w[x]-i)%MOD;
		}
		printf("%I64d\n",ans%MOD);
	}
	return 0;
}