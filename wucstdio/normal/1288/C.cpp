#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m;
ll c[2005][2005];
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
	scanf("%d%d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n;i++)
	  for(int j=i;j<=n;j++)
		ans=(ans+c[i+m-2][m-1]*c[n-j+m-1][m-1])%MOD;
	printf("%lld\n",ans);
	return 0;
}