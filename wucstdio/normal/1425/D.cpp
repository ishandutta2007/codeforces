#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m,r,x[2005],y[2005],s[2005];
ll b[2005],c[2005][2005];
bitset<2005>f[2005];
int main()
{
	c[0][0]=1;
	for(int i=0;i<=2000;i++)
	for(int j=0;j<=i;j++)
	{
		c[i][j]%=MOD;
		c[i+1][j+1]+=c[i][j];
		c[i+1][j]+=c[i][j];
	}
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;i++)scanf("%d%d%lld",&x[i],&y[i],&b[i]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=i;j++)
		if(max(abs(x[i]-x[j]),abs(y[i]-y[j]))<=r)
		  f[i][j]=1,f[j][i]=1;
	for(int i=1;i<=n;i++)s[i]=f[i].count();
	ll ans=0;
	for(int i=1;i<=n;i++)ans=(ans+b[i]*b[i]%MOD*(c[n][m]-c[n-s[i]][m]))%MOD;
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		int x=(f[i]&f[j]).count();
		ans=(ans+2*b[i]*b[j]%MOD*(c[n][m]-c[n-s[i]][m]-c[n-s[j]][m]+c[n-s[i]-s[j]+x][m]))%MOD;
	}
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}