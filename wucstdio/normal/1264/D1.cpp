#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll f[2005][2005],g[2005][2005];
int n;
char s[2005];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int last=0;last<i;last++)
		{
			f[i-1][last]%=MOD;
			if(s[i]!=')')f[i][last+1]+=f[i-1][last];
			if(s[i]!='(')f[i][last]+=f[i-1][last];
		}
	}
	g[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int last=0;last<n-i+1;last++)
		{
			g[i+1][last]%=MOD;
			if(s[i]!='(')g[i][last+1]+=g[i+1][last];
			if(s[i]!=')')g[i][last]+=g[i+1][last];
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=n;j>=0;j--)
		  g[i][j]=(g[i][j+1]+g[i][j])%MOD;
	}
	ll ans=0;
	for(int x=1;x<=n/2;x++)
	  for(int i=1;i<=n;i++)
		if(s[i]!=')')
		  ans+=f[i-1][x-1]*g[i+1][x]%MOD;
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}