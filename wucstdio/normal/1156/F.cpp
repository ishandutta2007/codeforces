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
int n,a[5005],num[5005];
ll f[5005][5005],s[5005][5005],inv[5005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
		inv[i]=quick_pow(i,MOD-2);
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=0;i<=n;i++)s[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==a[j-1])
			{
				ans+=f[i-1][j-1]*inv[n-i+1]%MOD*(num[a[j]]-1)%MOD;
				continue;
			}
			f[i][j]=s[i-1][j-1]*inv[n-i+1]%MOD*num[a[j]]%MOD;
		}
		for(int j=1;j<=n;j++)
		{
			s[i][j]=s[i][j-1]+f[i][j];
			if(s[i][j]>=MOD)s[i][j]-=MOD;
		}
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}