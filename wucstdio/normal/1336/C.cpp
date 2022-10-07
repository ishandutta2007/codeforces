#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m;
char s[3005],t[3005];
ll f[3005][3005],g[3005][3005],ans;
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
	scanf("%s%s",s+1,t+1);
	n=(int)strlen(s+1),m=(int)strlen(t+1);
	for(int i=1;i<=n/2;i++)swap(s[i],s[n-i+1]);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(m,i);j++)
		{
			f[i][j]=f[i-1][j];
			if(t[j]==s[i])f[i][j]+=f[i-1][j-1];
			if(f[i][j]>=MOD)f[i][j]-=MOD;
//			printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
		}
		f[i][0]=i+1;
		if(i!=n)ans=(ans+(f[i][m]-f[i-1][m]+MOD)*quick_pow(2,n-i))%MOD;
	}
//	printf("%lld\n",ans);
	for(int i=1;i<=m;i++)
		if(t[i]==s[n])g[i][i]=2;
	for(int len=2;len<=m;len++)
	{
		for(int l=1;l+len-1<=m;l++)
		{
			int r=l+len-1;
			if(s[n-len+1]==t[l])g[l][r]+=g[l+1][r];
			if(s[n-len+1]==t[r])g[l][r]+=g[l][r-1];
			if(g[l][r]>=MOD)g[l][r]-=MOD;
//			printf("g[%d][%d]=%lld\n",l,r,g[l][r]);
		}
	}
	ans=(ans+g[1][m])%MOD;
	for(int i=1;i<=n;i++)
	{
		if(n-i>m)continue;
		int suflen=n-i;
		ans=(ans+f[i-1][m-suflen]*g[m-suflen+1][m])%MOD;
//		if(suflen==m)ans=(ans+g[m-suflen+1][m])%MOD;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}